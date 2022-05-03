#include "BinSort.hpp"
using namespace std;

void bSort(vector<Film>& movies, vector<vector<Film>>& movieByRate) {
  for (auto movie : movies) {
    movieByRate[static_cast<int>(movie.getRating()) - 1].push_back(movie);
  }
}

void binSort(std::vector<Film> movies) {
  vector<Film> tmp = movies;
  vector<vector<Film>> movieByRate(10);
  bSort(tmp, movieByRate);
  saveToFile(movieByRate);
}

void saveToFile(vector<vector<Film>>& moviesByRate) {
  std::cout << "Sorted movies will be send to \"BSorted.txt\" file"
            << std::endl;
  std::ofstream newFile;
  std::string fileName = "BSorted.txt";
  newFile.open(fileName);
  if (newFile.good()) {
    newFile << "Sorted movies: \n";
    newFile << "Ordinal no.: Title Rating: \n";
    for (auto& movies : moviesByRate) {
      for (auto& element : movies)
        newFile << element.getOrdNo() << " " << element.getTitle() << " "
                << element.getRating() << std::endl;
    }
    std::cout << "File has been created or has been overwritten!" << std::endl;
  } else
    throw std::runtime_error("The file " + fileName + " could not be created!");
}