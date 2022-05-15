#ifndef FILM_HPP
#define FILM_HPP
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Film {
 private:
  uint64_t ordinalNo{};
  std::string title{};
  float rating{};
  Film(uint64_t _ordNo, std::string _title, float _rating);

 public:
  /**
   * @brief Construct a new Film object
   *
   */
  Film(){};
  /**
   * @brief Get the Ord No of object
   *
   * @return uint64_t - ordinal number
   */
  uint64_t getOrdNo() const { return ordinalNo; };
  /**
   * @brief Get the Rating of object
   *
   * @return float - rating
   */
  float getRating() const { return rating; };
  /**
   * @brief Get the Title of object
   *
   * @return std::string - title
   */
  std::string getTitle() const { return title; };
  /**
   * @brief Set the Ord No of object
   *
   * @param _ordinalNo - ordinal number
   */
  void setOrdNo(uint64_t _ordinalNo) { ordinalNo = _ordinalNo; };
  /**
   * @brief Set the Title of object
   *
   * @param _title - title
   */
  void setTitle(std::string _title) { title = _title; };
  /**
   * @brief Set the Rating of object
   *
   * @param _rating - rating
   */
  void setRating(float _rating) { rating = _rating; };
};

/**
 * @brief Overloaded operator of output stream
 *
 * @param stream - stream to which element will be printed
 * @param movie - movie to print
 * @return std::ostream& - printed data of movie
 */
std::ostream &operator<<(std::ostream &stream, const Film &movie);
#endif
