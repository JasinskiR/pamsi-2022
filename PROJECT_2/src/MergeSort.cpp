#include "MergeSort.hpp"

#include <algorithm>
using namespace std;

void mSort(std::vector<Film>& movieList, std::vector<Film>& tmp, int low,
           int high) {
  // Mid position of vector and iterators
  int middle, i1, i2, i;

  // Set the middle of the vector
  middle = (low + high + 1) / 2;
  if (middle - low > 1) mSort(movieList, tmp, low, middle - 1);
  if (high - middle > 0) mSort(movieList, tmp, middle, high);
  // Iteratir one is set as left value of first subvector
  i1 = low;
  // Iteratir two is set as left value of second subvector
  i2 = middle;

  // Now we compare elements from subvectors and copy the less value to
  // temporary vector to store sorted movies. As they were compared we increase
  // the iterator from this subvector from which the value was copied
  for (i = low; i <= high; i++)
    tmp[i] = ((i1 == middle) || ((i2 <= high) && (movieList[i1].getRating() >
                                                  movieList[i2].getRating())))
                 ? movieList[i2++]
                 : movieList[i1++];
  // Copies the vector of sorted movies to the output vector
  for (i = low; i <= high; i++) movieList[i] = tmp[i];
}

void mergeSort(std::vector<Film> movies, uint64_t number, Data* records) {
  std::vector<Film> tmp = {movies.begin(), movies.begin() + number};
  vector<vector<Film>> movieByRate(10);

  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  mSort(movies, tmp, 0, tmp.size() - 1);
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;

  records->checkSort(tmp);
  if (!records->getIfSorted()) {
    std::cout << "Movies were sorted incorrectly!" << std::endl;
    return;
  }

  records->setMedian(tmp);
  records->setAverage(tmp);
  records->setTime(elapsed_seconds.count());

  records->saveOrPrint(tmp, "MSorted.txt");
}