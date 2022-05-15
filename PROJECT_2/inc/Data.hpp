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
  /**
   * @brief Read data from file (to sort)
   *
   */
  void readFile();
  /**
   * @brief Add read string with movie data to vector
   *
   */
  void addMovie(std::vector<std::string>);
  /**
   * @brief Filter to read data
   *
   */
  void universalFilter();

  /**
   * @brief Get the All Movies object
   *
   * @return uint64_t - number of movies
   */
  uint64_t getAllMovies() { return allMovies; };
  /**
   * @brief Get the vector of Film objects
   *
   * @return std::vector<Film> - vector with movies
   */
  std::vector<Film> getMovies() { return movies; };
  /**
   * @brief Get the Number of objects
   *
   * @return uint64_t - number of objects - movies
   */
  uint64_t getNumber() { return numberOfMovies; };
  /**
   * @brief Get the Average Rating of all movies
   *
   * @return float - rating
   */
  float getAverageRating() { return average; };
  /**
   * @brief Get the Median of all movies
   *
   * @return float - median
   */
  float getMedian() { return median; };
  /**
   * @brief Get the Time of sorting of specific algorithm
   *
   * @return double - time of sorting
   */
  double getTime() { return time; };
  /**
   * @brief Get ifSorted boolean value
   *
   * @return true - if data are sorted correctly
   * @return false - in other cases
   */
  bool getIfSorted() { return ifSorted; };

  /**
   * @brief Set the Median of all movies
   *
   * @param toMedian - vector with movies from which the median will be count
   */
  void setMedian(std::vector<Film> toMedian);
  /**
   * @brief Set the Average of reating of all movies
   *
   * @param tmp - vector with movies form which the average rating will be count
   */
  void setAverage(std::vector<Film> tmp);
  /**
   * @brief Set the Time of sorting
   *
   * @param _time - time of sorting
   */
  void setTime(double _time) { time = _time; };
  /**
   * @brief Save or print or do nothing after sorting the elements
   *
   * @param films - vector with films
   * @param fileName - name of file to which sorted movies will be send
   */
  void saveOrPrint(std::vector<Film> films, std::string fileName);
  /**
   * @brief Chceck if movies were sorted correctly
   *
   * @param toCheck - vector with films to check correctness
   */
  void checkSort(std::vector<Film> toCheck);

  /**
   * @brief Function which parse the element from string to specific variables
   *
   * @param line - string read from file
   * @return std::vector<std::string> - vecotr with separeted data
   */
  std::vector<std::string> parser(std::string line);
};

#endif
