#include "QuickSort.hpp"
using namespace std;

#include <algorithm>

void partition(std::vector<Film>& movieList, int low, int high, int& i,
               int& j) {
  if (high - low <= 1) {
    if (movieList[high].getRating() < movieList[low].getRating()) {
      std::swap(movieList[high], movieList[low]);
    }
    i = low;
    j = high;
    return;
  }

  int middle = low;
  float pivot = movieList[high].getRating();
  while (middle <= high) {
    if (movieList[middle].getRating() < pivot) {
      std::swap(movieList[low++], movieList[middle++]);
    } else if (movieList[middle].getRating() == pivot) {
      middle++;
    } else if (movieList[middle].getRating() > pivot) {
      std::swap(movieList[middle], movieList[high--]);
    }
  }
  i = low - 1;
  j = middle;
}

void qSort(std::vector<Film>& movieList, int low, int high) {
  if (low >= high) return;

  int i = 0, j = 0;
  partition(movieList, low, high, i, j);
  qSort(movieList, low, i);
  qSort(movieList, j, high);
}

void quickSort(std::vector<Film> movies, uint64_t number, Data* records) {
  std::vector<Film> tmp = {movies.begin(), movies.begin() + number};

  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  qSort(tmp, 0, tmp.size() - 1);
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;

  records->checkSort(tmp);
  if (!records->getIfSorted()) {
    std::cout << "Movies were sorted incorrectly!" << std::endl;
    return;
  }

  records->setMedian(tmp, number);
  records->setAverage(tmp, number);
  records->setTime(elapsed_seconds.count());

  records->saveOrPrint(tmp, "QSorted.txt");
}