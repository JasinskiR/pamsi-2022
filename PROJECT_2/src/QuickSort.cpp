#include "QuickSort.hpp"

#include <algorithm>

// int partition(std::vector<Film>& movieList, int low, int high) {
//   int i = (low + high) / 2;
//   Film pivot = movieList[i];  // pivot
//   movieList[i] = movieList[high];

//   for (int j = i = low; i < high; ++i) {
//     if (movieList[i].getRating < pivot.getRating()) {
//       std::swap(movieList[i], movieList[j]);
//       j++;
//     }
//     movieList[high] = movieList[j];
//     movieList[j] = pivot;
//     if (low < j - 1) qSort(movieList, low, j - 1);
//     if (j + 1 < high) qSort(movieList, j + 1, high);
// }
void swap(Film &movie1, Film &movie2) {
  Film tmp = movie1;
  movie1 = movie2;
  movie2 = tmp;
}

void qSort(std::vector<Film>& movieList, int low, int high) {
  int i = (low + high) / 2;
  int j = 0;
  if (i < 0 || i >= movieList.size()) {
    exit(1);
  }
  Film pivot = movieList[i];  // pivot
  movieList[i] = movieList[high];

  for (j = i = low; i < high; ++i) {
    if (movieList[i].getRating() < pivot.getRating()) {
      swap(movieList[i], movieList[j]);
      j++;
    }
  }
  movieList[high] = movieList[j];
  movieList[j] = pivot;
  if (low < j - 1) qSort(movieList, low, j - 1);
  if (j + 1 < high) qSort(movieList, j + 1, high);
}

void quickSort(std::vector<Film> movies) {
  std::vector<Film> tmp = movies;
  qSort(tmp, 0, (int)tmp.size() - 1);
  saveToFile(tmp);
}

void saveToFile(std::vector<Film> movies) {
  std::cout << "Sorted movies will be send to \"QSorted.txt\" file"
            << std::endl;
  std::ofstream newFile;
  std::string fileName = "QSorted.txt";
  newFile.open(fileName);
  if (newFile.good()) {
    newFile << "Sorted movies: \n";
    newFile << "Ordinal no.: Title Rating: \n";
    for (auto element : movies) {
      newFile << element.getOrdNo() << " " << element.getTitle() << " "
              << element.getRating() << std::endl;
    }
    std::cout << "File has been created or has been overwritten!" << std::endl;
  } else
    throw std::runtime_error("The file " + fileName + " could not be created!");
}