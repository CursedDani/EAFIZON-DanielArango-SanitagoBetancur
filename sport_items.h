#include "items.h"
#include <iostream>
using namespace std;


#ifndef SPORT_H
#define SPORT_H
class Sport_items : public Items {

public:
  
  Sport_items(int type, string name, int id, float price, int disp)
      : Items(type, name, id, price, disp) {}

  
};

#endif