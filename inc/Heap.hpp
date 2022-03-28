#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <vector>

template <typename message>
class Heap {
 private:
  uint32_t sizeOfTab{};
  uint32_t size{};
  std::pair<uint32_t, message> *packetArr;
  void addPackets(std::vector<std::pair<uint32_t, message>> _pack);
  void heapify(uint32_t node);
  std::pair<uint32_t, message> minValue();
  void pushDown(uint32_t node);
  void pop();
  void insertKey(std::pair<uint32_t, message> element);
  void resize();
  uint32_t getSize();

 public:
  Heap(std::vector<std::pair<uint32_t, message>> _pack);
  void print();
};
#include "Heap.tpp"
#endif