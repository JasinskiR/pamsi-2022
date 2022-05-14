#include "Data.hpp"

#include <bits/stdc++.h>

void Data::readFile() {
  lines.erase(lines.begin(), lines.end());
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
  // filter(lines.size());
  universalFilter(lines.size());
  allMovies = numberOfMovies;
}

void Data::filter(uint64_t amount) {
  clearVar();
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

void Data::clearVar() {
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
void Data::setAverage(std::vector<Film> tmp, uint64_t number) {
  average = std::accumulate(tmp.begin(), tmp.end(), 0,
                            [](int i = 0, const Film& movie) {
                              return movie.getRating() + i;
                            }) /
            (float)number;
}
void Data::universalFilter(uint64_t amount) {
  clearVar();
  for (uint64_t i = 0; i < lines.size(); ++i) {
    addMovie(parser(lines.at(i)));
  }
}

std::vector<std::string> Data::parser(std::string line) {
  std::vector<std::string> parsedLine;
  std::string column;
  std::string quoted;

  std::stringstream tmp(line);
  bool withQuote = false;
  std::string part = "";
  while (std::getline(tmp, column, ',')) {
    std::stringstream quote(column);
    do {
      auto position = column.find("\"");
      if (position != std::string::npos) {
        withQuote = !withQuote;
        part += column.substr(0, position + 1);
        column = column.substr(position + 1, column.size());
      }
    } while (std::getline(quote, quoted, '\"'));

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

void Data::saveOrPrint(std::vector<Film> films, std::string fileName) {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<int>::max(), '\n');
  bool status = true;
  while (status) {
    std::cout << "What do you want to do ?\n";
    std::cout << "P - print sorted movies out\n";
    std::cout << "S - save sorted movies to file\n";
    std::cout << "N - do not save or print\n";
    std::cout << "Your choice: ";
    char choice;
    while (true) {
      std::cin >> choice;
      if (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cout << "Option selection error. Try again: " << std::endl;
        continue;
      } else
        break;
    }
    switch (choice) {
      case 'p':
      case 'P': {
        std::cout << "Sorted movies: \n";
        std::cout << "Ordinal no.: Title: Rating: \n";
        for (auto element : films) {
          std::cout << element;
        }
        status = false;
        break;
      }
      case 's':
      case 'S': {
        std::cout << "Sorted movies will be send to \"" << fileName << "\" file"
                  << std::endl;
        std::ofstream newFile;
        newFile.open(fileName);
        if (newFile.good()) {
          newFile << "Sorted movies: \n";
          newFile << "Ordinal no.: Title: Rating: \n";
          for (auto element : films) {
            newFile << element;
          }
          std::cout << "File has been created or has been overwritten!"
                    << std::endl;
        } else
          throw std::runtime_error("The file " + fileName +
                                   " could not be created!");
        status = false;
        break;
      }
      case 'n':
      case 'N': {
        status = false;
        break;
      }
      default: {
        std::cout << "Unrecognized option !" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
      }
    }
  }
}