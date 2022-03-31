#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <string>
#include <vector>

template <typename message>
class Heap {
 private:
  uint32_t sizeOfTab{};
  uint32_t size{};
  std::pair<uint32_t, message> *packetArr;

  /**
   * @brief Method which is resbonsible for aadding packets to structure
   *
   * @param _pack  - vector of packets with messages
   */
  void addPackets(std::vector<std::pair<uint32_t, message>> _pack);

  /**
   * @brief Heapifing - method places the new element as high as it is possible
   * If the element is lower than its parrent they are swaped
   *
   * @param node - the element which is added to heap
   */
  void heapify(uint32_t node);

  /**
   * @brief The function return the lowest value at the heap (it is the root of
   * it)
   *
   * @return std::pair<uint32_t, message> - pair which is the first element on
   * heap
   */
  std::pair<uint32_t, message> minValue();

  /**
   * @brief Function push down the element - if it is higher than its child it
   * is swaped
   *
   * @param node current element
   */
  void pushDown(uint32_t node);

  /**
   * @brief Method which is swaping the last element on the heap with the first
   * one. The last one which is the lowest is set to NULL
   *
   */
  void pop();

  /**
   * @brief Method responsible for adding the element to the heap
   *
   * @param element - pair which is added
   */
  void insertKey(std::pair<uint32_t, message> element);

  /**
   * @brief Function which will resize the array if it is full
   *
   */
  void resize();

  /**
   * @brief Get the size - numbers of elements in the array
   *
   * @return uint32_t
   */
  uint32_t getSize();

 public:
  /**
   * @brief Construct a new Heap object
   *
   * @param _pack
   */
  Heap(std::vector<std::pair<uint32_t, message>> _pack);

  /**
   * @brief Print the heap out
   *
   */
  void print();
};
#include "Heap.tpp"
#endif