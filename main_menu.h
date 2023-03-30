#include "admin.h"
#include "client.h"

class Menu {

public:
  Inventory_list listt;
  Menu() {}

  void main_menu() {
    Admin admin;
    Client client;
    while (true) {
      std::cout << "\n";
      std::cout << "///////////// WELCOME TO EAFIZON.COM /////////////\n"
                << std::endl;
      int ad_or_cl_opt;
      std::cout << "\n";
      std::cout << "PLEASE, SELECT IF YOU ARE AN ADMIN (press 1) OR CLIENT "
                   "(press 2): ";
      std::cin >> ad_or_cl_opt;
      if (ad_or_cl_opt == 1 || ad_or_cl_opt == 2) {
        if (ad_or_cl_opt == 1) {
          std::cout << "___________________________________________________\n"
                    << std::endl;
          admin.menu();
        }
        if (ad_or_cl_opt == 2) {

          client.menu();
        }
      }
    }
  }
};