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

  while (!file.eof()) {
    if (!getline(file, tmp)) continue;

    lines.push_back(tmp);
  }
  universalFilter(lines.size());
  allMovies = numberOfMovies;
}

void Data::filter(uint64_t amount) {
  clear();
  Film movie;
  for (uint64_t i = 0; i < lines.size(); ++i) {
    if (lines[i].size() == 0) continue;
    auto comma = lines[i].find(",");
    if (comma == 0 || comma == std::string::npos) continue;
    movie.setOrdNo(stoi(lines[i].substr(0, comma)));

    uint8_t titleBegin = comma + 1;
    // reading a comma 5 char from the end - rating position
    comma = lines[i].find(",", lines[i].size() - 5);
    if (comma == std::string::npos) continue;
    movie.setTitle(lines[i].substr(titleBegin, comma - titleBegin));

    auto ratingBegin = comma + 1;
    if (ratingBegin != lines.size()) {
      try {
        movie.setRating(std::stof(
            lines[i].substr(ratingBegin, lines.size() - ratingBegin)));
      } catch (std::invalid_argument const& ex) {
        continue;
      }
      numberOfMovies++;
      movies.push_back(movie);
      average += movie.getRating();
      if (amount == numberOfMovies) break;
    }
  }
}

void Data::clear() {
  movies.erase(movies.begin(), movies.end());
  numberOfMovies = 0;
  average = 0;
  median = 0;
}

void Data::setMedian(std::vector<Film> tmp, uint64_t number) {
  median =
      number % 2
          ? tmp[number / 2].getRating()
          : ((tmp[number / 2].getRating() + tmp[(number / 2) - 1].getRating()) /
             2);
}

void Data::universalFilter(uint64_t amount) {
  clear();
  for (uint64_t i = 0; i < lines.size(); ++i) {
    addMovie(parser(lines.at(i)));
  }
}

std::vector<std::string> Data::parser(std::string line) {
  std::vector<std::string> parsedLine;
  std::string column;

  std::stringstream tmp(line);
  bool withQuote = false;
  std::string part = "";
  while (std::getline(tmp, column, ',')) {
    auto position = column.find("\"");
    if (position != std::string::npos) {
      withQuote = !withQuote;
      part += column.substr(0, position);
      column = column.substr(position + 1, column.size());
    }
    if (!withQuote) {
      column += part;
      parsedLine.emplace_back(std::move(column));
      part = "";
    } else {
      part += column + ",";
    }
  }
  return parsedLine;
}

void Data::addMovie(std::vector<std::string> parsed) {
  Film movie;
  if (parsed.size() == 3) {
    try {
      movie.setOrdNo(stoul(parsed.at(0)));
    } catch (std::invalid_argument const& ex) {
      return;
    }
    try {
      movie.setTitle(parsed.at(1));
    } catch (std::invalid_argument const& ex) {
      return;
    }
    try {
      movie.setRating(stof(parsed.at(2)));
    } catch (std::invalid_argument const& ex) {
      return;
    }
    movies.emplace_back(movie);
    numberOfMovies++;
  }
}