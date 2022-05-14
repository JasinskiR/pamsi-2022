#include "MergeSort.hpp"

#include <algorithm>
using namespace std;

void mSort(std::vector<Film>& movieList, std::vector<Film>& tmp, int low,
           int high) {
  int middle, i1, i2, i;

  middle = (low + high + 1) / 2;
  if (middle - low > 1) mSort(movieList, tmp, low, middle - 1);
  if (high - middle > 0) mSort(movieList, tmp, middle, high);
  i1 = low;
  i2 = middle;
  for (i = low; i <= high; i++)
    tmp[i] = ((i1 == middle) || ((i2 <= high) && (movieList[i1].getRating() >
                                                  movieList[i2].getRating())))
                 ? movieList[i2++]
                 : movieList[i1++];
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

  records->setMedian(tmp, number);
  records->setAverage(tmp, number);
  records->setTime(elapsed_seconds.count());

  records->saveOrPrint(tmp, "MSorted.txt");
}