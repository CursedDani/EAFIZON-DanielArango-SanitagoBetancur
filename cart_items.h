#include "List.h"
#include "inventory_list.h"

#ifndef CART_H
#define CART_H

class Cart_items : public List {

public:
  void add_to_cart(Items *item) {

    if (head == NULL) {
      if (item->get_id() > 0) {
        head = new Node(item);
        cout << "New item in your Cart\n";
        size++;
      }
    } else {

      Node *current = head;

      while (current->next != NULL) {
        current = current->next;
      }
      if (current->value->get_disp() > 0) {
        current->next = new Node(item);
        size++;
        cout << "New item in your Cart, TOTAL ITEMS: " << size << endl;
      } else {
        cout << "Error: This item is'nt available, please select another.\n"
             << endl;
      }
    }
  }

  void show_cart() {
    Node *current = head;
    cout << "\n" << endl;
    cout << "/////////////  MY CART  ////////////" << endl;

    while (current != NULL) {
      if (current->value->get_id() > 0 && size > 0) {

        cout << "\n"
             << "Name:         " << current->value->get_name() << "\n"
             << "Price:        " << current->value->get_price() << "\n"
             << "_______________________________________" << endl;
      }
      current = current->next;
    }
  }

  void empty_cart() {
    Node *current = head;

    while (current != NULL) {
      Node *c_next = current->next;
      delete current;
      size--;
      current = c_next;
    }
    head = NULL;
    cout << "Your cart was emptied\n";
  }

  void add_prices() {
    Node *current = head;
    float add = 0;
    while (current != NULL) {
      add += current->value->get_price();
      if(current->value->get_type() == 3 ){
        
      }
      current = current->next;
    }
    cout << " TOTAL: " << add << " ?" << endl;
  }



  int return_size() { return this->size; }

  void buy_cart() {
    if (head->value->get_id() != 0) {
      Node *current = head;
      Node *prev = current;

      cout << "Do you want to pay?";
      add_prices();
      cout << "\n1 to buy Cart, 2 to cancel transaction: ";
      int opt;
      cin >> opt;
      if (opt == 1) {
        empty_cart();
        cout << "\n" << endl;
        cout << "Successful Purchase!" << endl;
      }

    } else {
      empty_cart();
      cout << "\n" << endl;
      cout << "Purchased Canceled" << endl;
    }
  }
};
#endif