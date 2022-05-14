#ifndef DATA_HPP
#define DATA_HPP
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Film.hpp"

//  ordinal no. ; title; rating
class Data {
 private:
  std::vector<Film> movies;
  std::vector<std::string> lines;
  uint64_t numberOfMovies{};
  uint64_t allMovies{};
  float average{};
  float median{};
  void clearVar();
  double time{};
  bool ifSorted{};

 public:
  void readFile();
  void addMovie(std::vector<std::string>);
  void filter(uint64_t amount);
  void universalFilter(uint64_t amount);

  uint64_t getAllMovies() { return allMovies; };
  std::vector<Film> getMovies() { return movies; };
  uint64_t getNumber() { return numberOfMovies; };
  float getAverageRating() { return average; };
  float getMedian() { return median; };
  double getTime() { return time; };
  bool getIfSorted() { return ifSorted; };

  void setMedian(std::vector<Film> toMedian, uint64_t number);
  void setAverage(std::vector<Film> tmp, uint64_t number);
  void setTime(double _time) { time = _time; };
  void saveOrPrint(std::vector<Film> films, std::string fileName);
  void checkSort(std::vector<Film> toCheck);

  std::vector<std::string> parser(std::string line);
};

#endif

/* IDEAS OF CONTAINING
vector of tuples
  param1 ordinal no.
  param2 title
  param3 year of airing
  param4 rating

HOW TO READ DATA
  - read whole line and then pars it with "," comma symbol
    there need to be some for or while to search through read line
  - up to date reading and parsing

QUESTIONS
Can we edit csv files (instead of comma -> white signs - space) or it has to
read read from original file
If something has the same rate now we should sort
using ordinal no.

*/

/*EDIT
NEED TO READ ORIGINAL FILE WITH COMMA
STL CONTEINERS CAN BE USED
AFTER SORTING BY RATE OTHER CAN BE SORT AS YOU WISH
*/