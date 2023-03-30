#include "List.h"
#include "foreing_item.h"
#include <iostream>
using namespace std;
#ifndef INVENTORY_H
#define INVENTORY_H
class Inventory_list {

private:
  Node *head = NULL;
  int size = 0;

public:
  void add_item(Items *item) {
    if (head == NULL) {
      head = new Node(item);
      size++;
      cout << "New item was added" << endl;
    } else {

      Node *current = head;

      while (current->next != NULL) {
        current = current->next;
      }
      current->next = new Node(item);
      size++;
      cout << "New item was added, new size: " << size << endl;
    }
  }

  bool exist_item(int id) {

    bool exist = false;
    Node *current = head;

    while (current != NULL) {

      if (current->value->get_id() == id) {
        exist = true;
        return exist;
      }
      current = current->next;
    }
    return exist;
  }

  void change_atributes(int id, int opt) {
    bool exist = exist_item(id);
    if (exist == true && opt > 0 && opt < 4) {
      Node *current = head;
      while (current != NULL) {
        if (current->value->get_id() == id) {
          switch (opt) {

          case 1: {
            string n;
            cout << "Enter the new 'name' of item: ";
            cin >> n;
            current->value->set_name(n);
            cout << "Change successful"
                 << "\n";
            break;
          }
          case 2: {
            float price;
            cout << "Enter the new Price of item: ";
            cin >> price;
            current->value->set_price(price);
            cout << "Change successful"
                 << "\n";
            break;
          }
          case 3: {
            int disp;
            cout << "Enter the new Disp of item: ";
            cin >> disp;
            current->value->set_disp(disp);
            cout << "Change successful"
                 << "\n";
            break;
          }
          }
        }
        current = current->next;
      }

    } else {

      cout << "The item doesn´t exist or out of range in the options" << endl;
    }
  }

  void delete_item(int id) {
    bool exist = exist_item(id);
    if (exist == true) {

      Node *current = head;
      Node *c_next = current->next;
      Node *prev = NULL;

      if (head == NULL) {
        cout << "Error: The list is empty" << endl;
      }
      if (head->value->get_id() == id) {
        head = head->next;
        size--;
        cout << "The article was deleted, new size: " << size << endl;
      } else {
        while (c_next) {
          prev = current;
          current = c_next;
          c_next = c_next->next;
          if (current->value->get_id() == id) {
            prev->next = c_next;
            size--;
            cout << "The article was deleted, new size: " << size << endl;
            delete current;
            break;
          }
        }
      }
    } else {
      cout << "The article doesn´t exist" << endl;
    }
  }

  void total_inventory_list() {
    Node *current = head;
    cout << "\n//////////////////   TOTAL INVENTORY  ////////////////////"
         << endl;
    if (head == NULL) {
      cout << "\n";
      cout << "The list is empty\n";
    }
    while (current != NULL) {

      cout << "\n"

           << "Name:         " << current->value->get_name() << "\n"
           << "Id:           " << current->value->get_id() << "\n"
           << "Price:        " << current->value->get_price() << "\n"
           << "Current Disp: " << current->value->get_disp() << "\n"
           << "_______________________________________\n"
           << endl;
      current = current->next;
    }
  }

  void show_sport_items() {

    Node *current = head;

    cout << "\n" << endl;
    cout << "/////////////  SPORT ITEMS  ////////////" << endl;

    while (current != NULL) {
      if (current->value->get_type() == 2 && current->value->get_id() > 0 &&
          size > 0) {

        cout << "\n"
             << "Id:            " << current->value->get_id() << "\n"
             << "Name:          " << current->value->get_name() << "\n"
             << "Price:         " << current->value->get_price() << "\n"
             << "_______________________________________" << endl;
      }
      current = current->next;
    }
  }

  void show_th_items() {
    Node *current = head;

    cout << "\n" << endl;
    cout << "/////////////  TECH ITEMS  ////////////" << endl;

    while (current != NULL) {
      if (current->value->get_type() == 1 && current->value->get_id() > 0 &&
          size > 0) {

        cout << "\n"
             << "Id:            " << current->value->get_id() << "\n"
             << "Name:          " << current->value->get_name() << "\n"
             << "Price:         " << current->value->get_price() << "\n"
             << "_______________________________________" << endl;
      }
      current = current->next;
    }
  }

  Items *return_item(int id) {

    Node *current = head;
    Items *null_article = new Items(0, "", 0, 0, 0);
    bool exist = exist_item(id);
    if (exist == true) {

      while (current != NULL) {
        if (current->value->get_id() == id && current->value->get_disp() > 0) {
          current->value->set_disp(current->value->get_disp() - 1);
          return current->value;
        }

        current = current->next;
      }

    } else {
      cout << "Id: " << id << " not found" << endl;
    }

    return null_article;
  }

  Inventory_list() {}
};
#endif