#include "items.h"
#include <iostream>

#ifndef NODE_H
#define NODE_H
class Node {

public:
  Items *value;
  Node *next;

  Node(Items *value) {
    this->value = value;
    this->next = NULL;
  }
};
#endif