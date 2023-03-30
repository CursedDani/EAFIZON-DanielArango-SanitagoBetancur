#include "User.h"
#include "inventory_list.h"

#ifndef ADMIN_H
#define ADMIN_H

class Admin : User {

private:
  Inventory_list list;

  void add_to_inventory(Items *item) { list.add_item(item); }

  bool exist(int id) { return list.exist_item(id); }

  void delete_item(int id) { list.delete_item(id); }

  void change_atributes(int id, int opt) { list.change_atributes(id, opt); }

  void show_inventory() { list.total_inventory_list(); }

  void show_sp_items() { list.show_sport_items(); }

  void show_th_items() { list.show_th_items(); }

public:

  int item_type;
  string name_item;
  int item_id;
  float item_price;
  int item_disp;

  void menu() {
    std::cout << "\n";
    std::cout << "/////////////////   WELCOME ADMIN   ////////////////\n"
              << std::endl;

    int admin_section;
    std::cout
        << "\n1 to ADD a new item\n2 to MODIFY an item\n3 to DELETE an item\n";

    std::cin >> admin_section;
    std::cout << "\n" << std::endl;
    if (admin_section > 0 && admin_section < 4) {
      if (admin_section == 1) {
        std::cout << "/////////////////   ADD NEW ITEM   //////////////////\n"
                  << std::endl;
        
        std::cout
            << "ENTER TYPE OF ITEM (1 to Tech, 2 to Sport or 3 to foreing): ";
        std::cin >> item_type;
        std::cout << "\n" << std::endl;
        if (item_type != 1 && item_type != 2 && item_type != 3) {
          cout << "\n Error, items can only be type 1, 2 or 3" << endl;
        } else {

          
          std::cout << "ENTER  NAME (WITHOUT SPACES): ";
          std::cin >> name_item;
          std::cout << "\n" << std::endl;
          
          std::cout << "ENTER ID (different to 0): ";
          std::cin >> item_id;
          bool repit_id = exist(item_id);
          if (repit_id == true || item_id == 0) {
            std::cout << "Error: The ID is unique per item or should be "
                         "different to 0\n";
          } else {
            std::cout << "\n" << std::endl;
            
            std::cout << "ENTER PRICE (FLOAT WITH '.'): ";
            std::cin >> item_price;
            std::cout << "\n" << std::endl;
            
            
            std::cout << "ENTER DISPONIBILITY AMOUNT: ";
            std::cin >> item_disp;
            std::cout << "\n" << std::endl;

          }
        }
      }
      
      if (admin_section == 2) {
        std::cout
            << "///////////////////  MODIFY  ARTICLE  ///////////////////\n"
            << std::endl;
        int id_art_change;
        std::cout << "ENTER ID ARTICLE: ";
        std::cin >> id_art_change;
        std::cout << "\n" << std::endl;
        int opt;
        std::cout << "CHANGE: (1 to name, 2 to price, 3 to disp: ";
        std::cin >> opt;
        std::cout << "\n" << std::endl;
        change_atributes(id_art_change, opt);
      }
      if (admin_section == 3) {
        std::cout << "////////////////  DELETE ARTICLE  //////////////////\n"
                  << std::endl;
        int id_delete;
        std::cout << "ENTER ID ARTICLE: ";
        std::cin >> id_delete;
        delete_item(id_delete);
      }
      int ls_opt;
      std::cout << "_____________________________________________\n"
                << std::endl;
      std::cout << "Enter 0 to show inventory or 1 to exit: \n";
      std::cin >> ls_opt;
      if (ls_opt == 0) {
        show_inventory();
      }
    } else {

      std::cout << "error: option out of range\n" << std::endl;
    }
  }

  int get_type(){
    return item_type;
  }
  string get_name(){
    return name_item;
  }
  float get_price(){
    return item_price;
  }

  int get_disp(){
    return item_disp;
  }

  int get_id(){
    return item_id
  }


};

#endif