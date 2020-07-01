#include "menu.h"
#include "management.h"
#include "structures.h"
#include "libraries/password.h"
#include "user.h"
#include "admin.h"
#include "init.h"

namespace lablnet { // lablnet

  void managementMenu()
  {
    bool logged = true;
    int sap;
    std::string password;
    std::cout << "### Let's Login ###\n";
    std::cout << "Enter your SAP ID: ";
    std::cin >> sap;
    std::cin.ignore();
    password = lablnet::getpass("Enter your password: ", true);
    long long int pass = lablnet::getPassBySap(sap);
    if (pass != -1) {
      // validate the password.
      if (lablnet::verify(&password, &pass)) {
        // Determine is really admin?
        if (lablnet::isAdmin(&sap)) {
          lablnet::adminMenu();
        } else
          logged = false;
      } else
        logged = false;
    } else
      logged = false;

    if (logged == false) {
      std::cout << "\nSorry, wrong username or password! \n";
      lablnet::managementMenu();
    }
  }
} // End lablnet
