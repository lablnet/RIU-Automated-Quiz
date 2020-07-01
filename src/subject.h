#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED

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
  void reaSubjectDataInStructures(char delim = ',')
  {
    subjects = {};
    std::ifstream subs;
    subs.open("storage/subjects.csv");
    if (!subs)
    {
        std::cout << "File not open\n";
        exit(1);
    }
    std::string line;
    while (std::getline(subs, line))
    {
        std::istringstream ss(line);
        Subject subject;
        std::getline(ss, subject.name,delim);
        subjects.push_back(subject);
    }
    subs.close();
  }
  void displaySubject()
  {
    reaSubjectDataInStructures();
    for (int i = 0; i < subjects.size(); i++)
        std::cout << "Enter " << i+1 << " for " << subjects[i].name
             << '\n';
    return;
  }
  inline bool isSubject(char *file)
  {
    if (std::ifstream(file))
      return true;

    return false;
  }
  void addSubjct(void)
  {
    std::string name;
    std::cout << "Enter subject name: ";
    std::cin.ignore();
    std::getline (std::cin,name);

    std::ofstream subjects;
  	subjects.open("storage/subjects.csv", std::ios::app);
    std::ofstream subject;
    std::string filename = "storage/" + name + ".csv";
  	subject.open(filename, std::ios::app);
    subject << "";
    subject.close();
    if (!subjects)
    {
        std::cout << "File not open\n";
        exit(1);
    }
  	subjects << name << std::endl;
  	subjects.close();
    return;
  }
  void subjectSelector()
  {
    std::cout << "Enter name of subject from given below: \n";
    lablnet::displaySubject();
    return;
  }
  void subjectManagement()
  {
    lablnet::clear();
    int option;
    std::cout << "### Admin Area ###\n";
    std::cout << "Enter 1 for add subject \n";
    std::cin >> option;
    if (option == 1)
      lablnet::addSubjct();
    else {
      std::cout << "\nWrong choice!\n";
      return;
    }
  }
} // End lablnet

#endif // SUBJECT_H_INCLUDED
