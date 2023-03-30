#include <iostream>
using namespace std; 

#ifndef ITEM_H
#define ITEM_H
class Items {

protected:
  int type;
  string name;
  int id;
  float price;
  int disp;
  

public:
  Items(int type, string name, int id, float price, int disp) {
    this->type = type;
    this->name = name;
    this->id = id;
    this->price = price;
    this->disp = disp;
  }

  int get_type() { return type; }

  string get_name() { return name; }

  int get_id() { return id; }

  float get_price() { return price; }

  int get_disp() { return disp; }


  void set_type(int t) { type = t; }

  void set_name(string n) { name = n; }

  void set_id(int i) { id = i; }

  void set_price(float p) { price = p; }

  void set_disp(int d) { disp = d; }

  Items() {}
};
#endif