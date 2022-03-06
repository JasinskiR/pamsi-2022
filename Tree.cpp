#include "Tree.hpp"

Tree::Tree() : value(NULL), left(NULL), right(NULL) {}

void Tree::add(uint32_t value) {
  Tree *now = this;
  Tree *addedN = NULL;

  addedN->value = value;
  addedN->left = NULL;
  addedN->right = NULL;

  if (this == NULL) {
    now = addedN;
    return;
  } else {
    while (now != NULL) {
      if (now->value <= addedN->value) {
        if (now->right == NULL) {
          now->right = addedN;
          return;
        } else {
          now = now->right;
        }
      }
      if (now->value > addedN->value) {
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