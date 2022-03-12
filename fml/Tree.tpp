#include "Tree.hpp"
#include "assert.h"

template <typename message>
Tree<message>::Tree() {
  root = NULL;
  treeSize = 0;
}

template <typename message>
Tree<message>::~Tree() {
  deleteTree(root);
}

template <typename message>
void Tree<message>::deleteTree(Node *node) {
  if (node != NULL) {
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }
}

template <typename message>
void Tree<message>::addPackets(
    std::vector<std::pair<uint32_t, message>> _pack) {
  for (auto const &packet : _pack) {
    add(&root, packet);
  }
}

template <typename message>
void Tree<message>::add(Node **node, std::pair<uint32_t, message> _pack) {
  if (*node == NULL) {
    Node *tmp = new Node;
    tmp->element = _pack;
    tmp->left = NULL;
    tmp->right = NULL;
    *node = tmp;

    this->treeSize++;
  } else {
    if (_pack.first > (*node)->element.first) {
      add(&((*node)->right), _pack);
    } else {
      add(&((*node)->left), _pack);
    }
  }
}

template <typename message>
void Tree<message>::p_sort() {
  Node *tmp = new Node;
  std::cout << "Sorted message: \n";
  std::cout << "Ordinal number: \t Massage: \n";
  for (uint32_t i = 1; i <= treeSize; ++i) {
    tmp = root;

    while (tmp->element.first != i) {
      if (tmp->element.first < i) {
        tmp = tmp->right;
      } else {
        tmp = tmp->left;
      }
      assert(tmp != nullptr);
    }
    std::cout << tmp->element.first << "\t" << tmp->element.second << std::endl;
  }
}