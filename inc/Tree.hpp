#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>

template <typename message>
class Tree {
  class Node {
    public:
    std::pair<uint32_t, message> element;
    Node *left;
    Node *right;
  };

 private:
  uint32_t treeSize;
  Node *root;
  void deleteTree(Node *node);
  void add(Node *node, std::pair<uint32_t, message> _pack);

 public:
  Tree();
  ~Tree();
  void addPackets(std::vector<std::pair<uint32_t, message>> _pack);
  void p_sort();
};

#include "Tree.tpp"
#endif