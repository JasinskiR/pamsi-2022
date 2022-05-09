#ifndef DATA_HPP
#define DATA_HPP
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
  void clear();

 public:
  uint64_t getAllMovies() { return allMovies; };
  void readFile();
  std::vector<Film> getMovies() { return movies; };
  uint64_t getNumber() { return numberOfMovies; };
  void filter(uint64_t amount);
  void universalFilter(uint64_t amount);
  float getAverageRating() { return average; };
  float getMedian() { return median; };
  void setMedian(std::vector<Film> toMedian, uint64_t number);
  void setAverage(float _average) { average = _average; };
  std::vector<std::string> parser(std::string line);
  void addMovie(std::vector<std::string>);
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