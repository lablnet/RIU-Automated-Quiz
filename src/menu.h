#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// Include required header file.
#include "management.h"
#include "student.h"
#include "libraries/password.h"

namespace lablnet { // lablnet
  void menu()
  {
    lablnet::clear();
    int option;
    std::cout << "### PROJECT AUTUTOMATED QUIZ ###\n";
    std::cout << "### By Muhammad Umer Farooq ###\n### https://beinglearning.tech ###";
    std::cout << "\n### SAP 19681 ###\n### Let's Start ###\n";
    std::cout << "Enter 1 admin area\n";
    std::cout << "Enter 2 for Quiz (for students): ";
    std::cin >> option;
    if (option == 1)
      lablnet::managementMenu();
    else if (option == 2)
      lablnet::loggedIn();
    else
      std::cout << "Sorry, you choose wrong option\n";

    option = INT8_MAX;
    std::cout << "Would you like to repeat 0/1 ";
    std::cin >> option;
    if (option == 1)
      menu();
    else
      return;
  }
} // End lablnet
#endif // MENU_H_INCLUDED
