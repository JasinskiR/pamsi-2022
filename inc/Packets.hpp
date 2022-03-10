#ifndef PACKETS_HPP
#define PACKETS_HPP
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

template <typename message>
class Packets {
 private:
  uint32_t packetNo;

 public:
  std::vector<std::pair<uint32_t, message>> packetTab;
  Packets(uint32_t _packetNo);
  void shuffle();
};
#include "Packets.tpp"
#endif