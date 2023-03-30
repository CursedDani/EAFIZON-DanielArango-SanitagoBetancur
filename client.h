#include "admin.h"

#include "cart_items.h"
#include "inventory_list.h"

class Client : Admin {

public:
  Cart_items cart;

  Admin admin;

  void add_to_cart(Items *item) { cart.add_to_cart(item); }

  void empty_list() { cart.empty_cart(); }

  void show_sp_items() { admin.list.show_sport_items(); }
  void show_th_items() { admin.list.show_th_items(); }

  void show_list() { cart.show_cart(); }

  void prices_sum() { cart.add_prices(); }

  void buy_cart() { cart.buy_cart(); }

  int return_size() { return cart.return_size(); }

  void menu() {
    std::cout << "/////////////////  WELCOME CLIENT  //////////////////\n"
              << std::endl;
    show_sp_items();
    show_th_items();
    std::cout << "\n" << std::endl;
    std::cout << "ENTER ID ITEM TO ADD IN YOUR CART: ";
    int client_art_id;
    std::cin >> client_art_id;
    admin.show_sp_items();
    admin.show_th_items();
    Items *new_cart_item = admin.list.return_item(client_art_id);
    add_to_cart(new_cart_item);

    std::cout << "\n" << std::endl;
    if (return_size() > 0) {
      show_list();
      int buy_opt;
      std::cout << "ENTER 1 TO BUY CART OR 0 TO EXIT: ";
      std::cin >> buy_opt;
      if (buy_opt == 1) {
        cart.buy_cart();
      }
    }
  }

  
};
