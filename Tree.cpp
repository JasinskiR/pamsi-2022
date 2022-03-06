#include "Tree.hpp"

Tree::Tree() : value(NULL), left(NULL), right(NULL) {}

void Tree::add(uint32_t value) {
  Tree *now = this;
  Tree *added = NULL;

  added->value = value;
  added->left = NULL;
  added->right = NULL;

  if (this == NULL) {
    now = added;
    return;
  } else {
    while (now != NULL) {
      if (now->value <= added->value) {
        if (now->right == NULL) {
          now->right = added;
          return;
        } else {
          now = now->right;
        }
      }
      if (now->value > added->value) {
        if (now->left == NULL) {
          now->left = added;
          return;
        } else {
          now = now->left;
        }
      }
    }
  }
}