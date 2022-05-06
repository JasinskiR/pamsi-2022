#include "QuickSort.hpp"
using namespace std;

#include <bits/stdc++.h>

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

void quickSort(std::vector<Film> movies, uint64_t number) {
  std::vector<Film> tmp = movies;
  qSort(tmp, 0, number - 1);
  saveToFileQ(tmp, number);
}

void saveToFileQ(std::vector<Film> movies, uint64_t number) {
  std::cout << "Sorted movies will be send to \"QSorted.txt\" file"
            << std::endl;
  std::ofstream newFile;
  std::string fileName = "QSorted.txt";
  newFile.open(fileName);
  if (newFile.good()) {
    newFile << "Sorted movies: \n";
    newFile << "Ordinal no.: Title Rating: \n";
    for (uint64_t element = 0; element < number; ++element) {
      newFile << movies[element];
    }
    std::cout << "File has been created or has been overwritten!" << std::endl;
  } else
    throw std::runtime_error("The file " + fileName + " could not be created!");
}