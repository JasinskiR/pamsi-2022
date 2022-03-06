#include <iostream>
#include "Packets.hpp"
#include <time.h>
using namespace std;

int main() {
  srand(time(NULL));
  uint32_t packetNo;
  cout << "Enter the number of packets : ";
  cin >> packetNo;
  Packets packets(packetNo);
}