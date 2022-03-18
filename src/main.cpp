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
  Heap<uint32_t> heap;
  heap.addPackets(packets.packetTab);

  std::cout << "Sorted message: \n";
  std::cout << "Ordinal no.: Massage: \n";
  while (heap.getSize() > 0) {
    std::pair<uint32_t, uint32_t> tmp;
    tmp = heap.minValue();
    heap.pop();

    cout << tmp.first << "\t" << tmp.second << endl;
  }
}