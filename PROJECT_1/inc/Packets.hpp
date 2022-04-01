#ifndef PACKETS_HPP
#define PACKETS_HPP
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include <string>

template <typename message>
class Packets {
 private:
  uint32_t packetNo;
  void shuffle();

 public:
  std::vector<std::pair<uint32_t, message>> packetArr;
  Packets(uint32_t _packetNo);
  Packets();
};
#endif