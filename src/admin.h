#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "init.h"
#include "user.h"
#include "subject.h"

namespace lablnet { // lablnet

  void addQuestion()
  {
    std::string question, option1, option2, option3, option4, ans;
    int subNum;
    subjectSelector();
    std::cin >> subNum;
    subNum--;
    std::string name = subjects[subNum].name;
    std::string file = "storage/" + name + ".csv";
    std::ofstream q;
    std::string filename = "storage/" + name + ".csv";
    q.open(filename, std::ios::app);
    std::cout << "Enter Question: ";
    std::cin.ignore();
    std::getline(std::cin, question);
    std::cout << "Enter option 1: ";
    std::cin.ignore();
    std::getline(std::cin, option1);
    std::cout << "Enter option 2: ";
    std::cin.ignore();
    std::getline(std::cin, option2);
    std::cout << "Enter option 3: ";
    std::cin.ignore();
    std::getline(std::cin, option3);
    std::cout << "Enter option 4: ";
    std::cin.ignore();
    std::getline(std::cin, option4);
    std::cout << "Enter answer: ";
    std::cin.ignore();
    std::getline(std::cin, ans);
    q << question << "," << option1 << "," << option2 << "," << option3 << "," << option4 << "," << ans << std::endl;
    q.close();
    return;
  }
  void adminMenu()
  {
    lablnet::clear();
    int option;
    std::cout << "### Admin Area ###\n";
    std::cout << "Enter 1 for user management \n"
              << "Enter 2 for Subjct management \n"
              << "Enter 3 for questions Add questions \n";
    std::cin >> option;
    if (option == 1)
      lablnet::userManagement();
    else if (option == 2)
      lablnet::subjectManagement();
    else if (option == 3)
      lablnet::addQuestion();
    else {
      std::cout << "\nWrong choice!\n";
      return;
    }
  }
} // End lablnet

#endif //ADMIN_H_INCLUDED
