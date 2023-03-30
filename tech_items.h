#include "items.h"
#include <iostream>
using namespace std;

#ifndef TECH_H
#define TECH_H
class Tech_items : public Items {

public:
  Tech_items(int type, string name, int id, float price, int disp)
      : Items(type, name, id, price, disp) {}

};
#endif