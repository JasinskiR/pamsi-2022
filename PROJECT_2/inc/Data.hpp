#ifndef DATA_HPP
#define DATA_HPP
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Film.hpp"

//  ordinal no. ; title ; year ; rating
template <typename data2Sort>
class Data {
 private:
  std::vector<Film> movies;
  uint64_t numberOfMovies{};

 public:
  void readFile();
  std::vector<Film> getMovies() { return movies; };
  uint64_t getNumber() { return numberOfMovies; };
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