#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "init.h"
#include "user.h"
#include "subject.h"
#include "quiz.h"
#include "result.h"

namespace lablnet { // lablnet

  void studentMenu()
  {
    lablnet::clear();
    int option;
    std::cout << "### Student Area ###\n";
    std::cout << "Enter 1 for attempt quiz \n"
              << "Enter 2 for search result \n";
    std::cin >> option;
    if (option == 1)
      lablnet::attemptQuiz();
    else if (option == 2)
      lablnet::searchResult();
    else {
      std::cout << "\nWrong choice!\n";
      return;
    }
  }
  void loggedIn()
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
          lablnet::studentMenu();
      } else
        logged = false;
    } else
      logged = false;

    if (logged == false) {
      std::cout << "\nSorry, wrong username or password! \n";
      lablnet::loggedIn();
    }
  }
} // End lablnet

#endif //STUDENT_H_INCLUDED
