#include "Packets.hpp"
using namespace std;

Packets::Packets(uint32_t _packetNo) : packetNo(_packetNo) {
  for (int i = 0; i < packetNo; ++i) {
    packetTab[i] = draw(packetNo, i);
  }
}

uint32_t Packets::draw(uint32_t packetNo, int itr) {
  int value = (rand() % packetNo) + 1;
  if (!check(value, itr)) {
    return value;
  } else
    draw(packetNo, itr);
}

bool Packets::check(uint32_t value, int itr) {
  if (itr <= 0) return false;
  for (int i = 0; i < itr; ++i) {
    if (packetTab[i] == value)
      return true;
    else
      return false;
  }
}