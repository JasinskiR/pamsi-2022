#include "Packets.hpp"
using namespace std;

Packets::Packets(uint32_t _packetNo) : packetNo(_packetNo) {
  for (int i = 0; i < packetNo; ++i) {
    packetTab[i] = i;
  }
  shuffle();
}

void Packets::shuffle() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng(seed);
  std::shuffle(packetTab.begin(), packetTab.end(), rng);
}