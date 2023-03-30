#include "items.h"
#include <iostream>
using namespace std;


#ifndef FOREING_H
#define FOREING_H
class Foreing_items : public Items {

public:
  
  Foreing_items(int type, string name, int id, float price, int disp)
      : Items(type, name, id, price, disp) {}

  
};

#endif