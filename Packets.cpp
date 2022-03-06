#include "Packets.hpp"
using namespace std;


uint32_t draw(uint32_t packetNo) {
  for(int i = 0; i <packetNo; ++i) {
   (rand() % packetNo) + 1;
  }