#ifndef FILM_HPP
#define FILM_HPP
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

//  ordinal no. ; title ; year ; rating
class Film {
 private:
  uint64_t ordinalNo{};
  std::string title{};
  float rating{};
  Film(uint64_t _ordNo, std::string _title, float _rating);

 public:
  Film(){};
  uint64_t getOrdNo() const { return ordinalNo; };
  float getRating() const { return rating; };
  std::string getTitle() const { return title; };
  void setOrdNo(uint64_t _ordinalNo) { ordinalNo = _ordinalNo; };
  void setTitle(std::string _title) { title = _title; };
  void setRating(float _rating) { rating = _rating; };
  bool operator<(Film other) { return this->rating < other.rating; }
};

std::ostream &operator<<(std::ostream &stream, const Film &movie);
#endif
