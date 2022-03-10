#ifndef PACKETS_HPP
#define PACKETS_HPP
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

class Packets {
 private:
  uint32_t packetNo;
  friend class Tree;

 public:
  std::vector<uint32_t> packetTab;
  Packets(uint32_t _packetNo);
  void shuffle();
};
#endif