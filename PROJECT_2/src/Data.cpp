#include "Data.hpp"

void Data::readFile() {
  std::string tmp;
  std::cout << "Enter a file name: ";
  std::string fileName;
  std::cin >> fileName;

  std::fstream file;
  file.open(fileName, std::ios::in);
  if (!file.good()) {
    throw std::invalid_argument("The file " + fileName +
                                " was not opened properly or " + fileName +
                                "does not exist!");
  }
  Film movie;
  std::cout << std::setprecision(1) << std::fixed;
  int i = 0;
  while (!file.eof()) {
    // while (i != 100000) {
    if (!getline(file, tmp)) continue;

    if (tmp.size() == 0) continue;
    auto comma = tmp.find(",");
    if (comma == 0 || comma == std::string::npos) continue;
    movie.setOrdNo(stoi(tmp.substr(0, comma)));

    uint8_t titleBegin = comma + 1;
    // reading a comma 5 char from the end - rating position
    comma = tmp.find(",", tmp.size() - 5);
    if (comma == std::string::npos) continue;
    movie.setTitle(tmp.substr(titleBegin, comma - titleBegin));

    auto ratingBegin = comma + 1;
    if (ratingBegin != tmp.size()) {
      movie.setRating(
          std::stof(tmp.substr(ratingBegin, tmp.size() - ratingBegin)));
      i++;
      movies.push_back(movie);
    }
  }
}
