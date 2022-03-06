#include <iostream>
#include "Packets.hpp"
#include <time.h>
#include "Tree.hpp"
using namespace std;

int main() {
  srand(time(NULL));
  uint32_t packetNo;
  cout << "Enter the number of packets : ";
  cin >> packetNo;
  Packets packets(packetNo);
  Tree *tree;
  for (int i = 0; i< packetNo; ++i)
    tree->add(packets.packetTab[i]);
}