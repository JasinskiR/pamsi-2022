#include <iostream>

#include "Heap.hpp"
#include "Packets.hpp"
#include "Tree.hpp"
using namespace std;

int main() {
  uint32_t packetNo;
  cout << "Enter the number of packets : ";
  cin >> packetNo;
  Packets<uint32_t> packets(packetNo);
  // Tree<uint32_t> tree;
  // tree.addPackets(packets.packetTab);
  // tree.p_sort();
  Heap<uint32_t> heap(packets.packetTab);
  heap.print();
}


