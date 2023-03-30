// se crea una clase abstracta abierta al polimorfismo la cual contiene la
#include "node.h"
#include "sport_items.h"
#include "tech_items.h"

#ifndef LIST_H
#define LIST_H
class List {
public:
  Node *head = NULL;
  int size = 0;


  List() {}
  virtual ~List() {}
};
#endif