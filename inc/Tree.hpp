#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>

template <typename message>
class Tree {
 private:
  std::pair<uint32_t, message> pack;
  Tree *left;
  Tree *right;
  uint32_t quantity{};

 public:
  Tree(std::vector<std::pair<uint32_t, message>> _pack);
  void add(std::pair<uint32_t, message> _pack);
  void p_sort();
};
#include "Tree.tpp"
#endif