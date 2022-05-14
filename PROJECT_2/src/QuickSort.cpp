#include "QuickSort.hpp"
using namespace std;

#include <algorithm>

Film magic5(std::vector<Film> movieList, int low, int high) {
  if (high - low <= 5) {
    for (int k = low; k < high; ++k) {
      for (int l = k + 1; l <= high; ++l) {
        if (movieList[k].getRating() > movieList[l].getRating())
          std::swap(movieList[k], movieList[l]);
      }
    }
    return movieList[(low + high) / 2];
  }
  std::vector<Film> tmp;
  for (int i = low; i <= high; i += 5) {
    int j = std::min(high + 1, i + 5);
    std::vector<Film> v =
        std::vector<Film>(movieList.begin() + i, movieList.begin() + j);
    for (int k = 0; k < v.size() - 1; ++k) {
      for (int l = k + 1; l < v.size(); ++l) {
        if (v[k].getRating() > v[l].getRating()) std::swap(v[k], v[l]);
      }
    }
    tmp.push_back(v[v.size() / 2]);
  }
  return magic5(tmp, 0, tmp.size() - 1);
}

void qSort(std::vector<Film>& movieList, int low, int high) {
  Film pivot = magic5(movieList, low, high);
  int pivotIndex = 0, i = 0;

  for (i = low; i <= high; i++) {
    if (movieList[i].getTitle() == pivot.getTitle()) break;
  }

  movieList[i] = movieList[high];
  for (pivotIndex = i = low; i < high; ++i) {
    if (movieList[i].getRating() < pivot.getRating()) {
      swap(movieList[i], movieList[pivotIndex]);
      pivotIndex++;
    }
  }
  int sameRate = pivotIndex + 1;
  for (int k = pivotIndex + 1; k < high; k++) {
    if (movieList[k].getRating() == pivot.getRating()) {
      swap(movieList[k], movieList[sameRate]);
      sameRate++;
    }
  }

  movieList[high] = movieList[pivotIndex];
  movieList[pivotIndex] = pivot;
  if (low < pivotIndex - 1) qSort(movieList, low, pivotIndex - 1);
  if (sameRate < high) qSort(movieList, sameRate, high);
}

void quickSort(std::vector<Film> movies, uint64_t number, Data* records) {
  std::vector<Film> tmp = {movies.begin(), movies.begin() + number};

  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  qSort(tmp, 0, tmp.size() - 1);
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;

  records->setMedian(tmp, number);
  records->setAverage(tmp, number);
  records->setTime(elapsed_seconds.count());

  records->saveOrPrint(tmp, "QSorted.txt");
}