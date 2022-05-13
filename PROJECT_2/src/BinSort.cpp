#include "BinSort.hpp"

#include <bits/stdc++.h>
using namespace std;

void bSort(vector<Film>& movies, vector<vector<Film>>& movieByRate,
           uint64_t number) {
  for (uint64_t movie = 0; movie < number; ++movie) {
    movieByRate[static_cast<int>(movies[movie].getRating()) - 1].push_back(
        movies[movie]);
  }
}

void binSort(std::vector<Film> movies, uint64_t number, Data* records) {
  std::vector<Film> tmp = {movies.begin(), movies.begin() + number};
  std::vector<Film> sorted;
  vector<vector<Film>> movieByRate(10);
  bSort(tmp, movieByRate, tmp.size());

  for (auto& movies : movieByRate) {
    for (auto& element : movies) {
      sorted.emplace_back(element);
    }
  }
  records->setMedian(sorted, number);
  records->setAverage(std::accumulate(sorted.begin(), sorted.end(), 0,
                                      [](int i = 0, const Film& movie) {
                                        return movie.getRating() + i;
                                      }) /
                      (float)number);
  saveToFile(movieByRate, number);
}

void saveToFile(vector<vector<Film>>& moviesByRate, uint64_t number) {
  std::cout << "Sorted movies will be send to \"BSorted.txt\" file"
            << std::endl;
  std::ofstream newFile;
  std::string fileName = "BSorted.txt";
  newFile.open(fileName);
  if (newFile.good()) {
    newFile << "Sorted movies: \n";
    newFile << "Ordinal no.: Title Rating: \n";
    uint64_t saved = 0;
    for (auto& movies : moviesByRate) {
      for (auto& element : movies) {
        if (saved < number) {
          newFile << element;
          saved++;
        }
      }
    }
    std::cout << "File has been created or has been overwritten!" << std::endl;
  } else
    throw std::runtime_error("The file " + fileName + " could not be created!");
}