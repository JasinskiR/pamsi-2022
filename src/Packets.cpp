#include "Packets.hpp"

template <>
Packets<uint32_t>::Packets(uint32_t _packetNo) : packetNo(_packetNo) {
  for (uint32_t i = 0; i < packetNo; ++i) {
    packetTab.push_back(std::make_pair(i + 1, i + 1));  // iterator of messages
  }
  shuffle();
}

template <typename message>
void Packets<message>::shuffle() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng(seed);
  std::shuffle(packetTab.begin(), packetTab.end(), rng);
}

template class Packets<uint32_t>;