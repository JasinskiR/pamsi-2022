#include <iostream>
#include "draw.hpp"
#include <time.h>
using namespace std;

int main() {
  srand(time(NULL));
  uint32_t packetNo;
  cout << "Enter the number of packets : ";
  cin >> packetNo;
  uint32_t packets[packetNo];
  draw(packetNo);
}