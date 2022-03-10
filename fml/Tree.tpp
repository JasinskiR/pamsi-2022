#include "Tree.hpp"

template <typename message>
Tree<message>::Tree(std::vector<std::pair<uint32_t, message>> _pack)
    : left(NULL), right(NULL) {
  for (uint32_t i = 0; i < _pack.size(); ++i) {
    add(_pack[i]);
  }
  quantity = _pack.size();
}

template <typename message>
void Tree<message>::add(std::pair<uint32_t, message>) {
  Tree *now = this;
  Tree *addedN = NULL;

  addedN->pack.first = pack.first;
  addedN->left = NULL;
  addedN->right = NULL;

  if (now == NULL) {
    now = addedN;
    return;
  } else {
    while (now != NULL) {
      if (now->pack.first <= addedN->pack.first) {
        if (now->right == NULL) {
          now->right = addedN;
          return;
        } else {
          now = now->right;
        }
      }
      if (now->pack.first > addedN->pack.first) {
        if (now->left == NULL) {
          now->left = addedN;
          return;
        } else {
          now = now->left;
        }
      }
    }
  }
}

template <typename message>
void Tree<message>::p_sort() {
  Tree *now = this;
  std::cout << "Sorted message: \n";
  std::cout << "Ordinal number: \t Massage: \n";
  for (uint32_t i = 0; i < quantity; ++i) {
    now = this;
    while (now->pack.first != i + 1) {
      if (now->pack.first < i + 1) {
        now = now->right;
      } else {
        now = now->left;
      }
    }
    std::cout << now->pack.first << "\t" << now->pack.second << std::endl;
  }
}