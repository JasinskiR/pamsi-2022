#include "Film.hpp"

Film::Film(uint64_t _ordNo, std::string _title, float _rating)
    : ordinalNo(_ordNo), title(_title), rating(_rating) {}

std::ostream &operator<<(std::ostream &stream, const Film &movie) {
  stream << std::setprecision(1) << std::fixed;
  stream << movie.getOrdNo() << "," << movie.getTitle() << ","
         << movie.getRating() << std::endl;
  return stream;
}