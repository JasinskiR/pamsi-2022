#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include "Packets.hpp"

class Tree {
  uint32_t value;
  Tree *left;
  Tree *right;

 public:
  Tree();
  void add(uint32_t value);
};
#endif