#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

// Include required header file.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "libraries/password.h"
#include "init.h"


namespace lablnet { // lablnet
  void addUser(void)
  {
    std::string name, password;
    int isAdmin = 0, sap;
    std::cout << "Enter SAP ID of user: ";
    std::cin >> sap;
    std::cout << "Enter Name of user: ";
    std::cin.ignore();
    std::getline (std::cin,name);
    std::cout << "Enter password: ";
    std::getline (std::cin,password);
    std::cout << "Is this user is admin or student \n\t Enter 1 for admin, 2 for student: ";
    std::cin >> isAdmin;
    std::ofstream user;
  	user.open("storage/users.csv", std::ios::app);
    if (!user)
    {
        std::cout << "File not open\n";
        exit(1);
    }
  	user << sap << "," << name << "," << lablnet::hash(&password) << "," << isAdmin << std::endl;
  	user.close();
    return;
  }
  void readUserDataInStructures(char delim = ',')
  {
    users = {};
    std::ifstream user;
    user.open("storage/users.csv");
    if (!user)
    {
        std::cout << "File not open\n";
        exit(1);
    }
    std::string line;
    while (std::getline(user, line))
    {
        std::istringstream ss(line);
        User user;
        ss >> user.sap; ss.ignore(10, delim);
        std::getline(ss, user.name,delim);
        ss >> user.password; ss.ignore(10, delim);
        ss >> user.admin;
        users.push_back(user);
    }

    user.close();
    return;
  }
  std::string getNameBySap(int sap)
  {
    readUserDataInStructures();
    for (int i = 0; i < users.size(); i++) {
      if (sap == users[i].sap) {
        return users[i].name;
      }
    }
    return "";
  }
  bool isAdmin(int *sap)
  {
    readUserDataInStructures();
    for (int i = 0; i < users.size(); i++) {
      if (*sap == users[i].sap && users[i].admin == 1)
          return true;
    }
    return false;
  }
  long long int getPassBySap(int sap)
  {
    readUserDataInStructures();
    for (int i = 0; i < users.size(); i++) {
      if (sap == users[i].sap) {
        return users[i].password;
      }
    }
    return -1;
  }
  void reportUsers()
  {
    readUserDataInStructures();
    std::cout << std::setw(5)  << "SAP"
         << std::setw(25) << "Name"
         << '\n';
    for (int i = 0; i < users.size(); i++)
        std::cout << std::setw(5)  << users[i].sap
             << std::setw(25) << users[i].name
             << '\n';
  }

  void updateOrDeleteUser(bool update = false)
  {
    readUserDataInStructures();
    std::ofstream user;
    user.open ("storage/users.csv");
    int sap, isAdmin = 0;
    std::string name, password;
    if (update == true) {
      std::cout << "Enter new SAP ID of user: ";
      std::cin >> sap;
      std::cout << "Enter new Name of user: ";
      std::cin.ignore();
      std::getline (std::cin,name);
      std::cout << "Enter new password: ";
      std::getline (std::cin,password);
      std::cout << "Is this user is admin or student \n\t Enter 1 for admin, 2 for student: ";
      std::cin >> isAdmin;
    } else {
      std::cout << "Enter sap of user you want to delete: ";
      std::cin >> sap;
    }
    for (unsigned int i=0; i< users.size(); i++) {
      if (sap == users[i].sap) {
        if (update == true) {
          user << sap << "," << name << "," << lablnet::hash(&password) << "," << isAdmin << std::endl;
        }
        continue;
      }
      user << users[i].sap << "," << users[i].name << "," << users[i].password << "," << users[i].admin << std::endl;
    }
    user.close();
    return;
  }

  void userManagement()
  {
    lablnet::clear();
    int option;
    std::cout << "### Admin Area ###\n";
    std::cout << "Enter 1 for add user \n"
              << "Enter 2 for update user \n"
              << "Enter 3 for delete user \n";
    std::cin >> option;
    if (option == 1)
      lablnet::addUser();
    else if (option == 2)
      lablnet::updateOrDeleteUser(true);
    else if (option == 3)
      lablnet::updateOrDeleteUser(false);
    else {
      std::cout << "\nWrong choice!\n";
      return;
    }
  }
} // End lablnet

#endif // USER_H_INCLUDED
