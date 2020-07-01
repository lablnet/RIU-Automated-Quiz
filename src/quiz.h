#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED

// Include required header file.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iterator>

#include <random>

#include "libraries/password.h"
#include "libraries/str.h"
#include "init.h"

namespace lablnet { // lablnet
  void readQuizDataInStructures(std::string name, char delim = ',')
  {
    quizes = {};
    std::string file = "storage/" + name + ".csv";
    std::ifstream quiz;
    quiz.open(file);
    if (!quiz)
    {
        std::cout << "File not open\n";
        exit(1);
    }
    std::string line;
    while (std::getline(quiz, line))
    {
        std::istringstream ss(line);
        Quiz q;
        std::getline(ss, q.question, delim);
        std::getline(ss, q.option1, delim);
        std::getline(ss, q.option2, delim);
        std::getline(ss, q.option3, delim);
        std::getline(ss, q.option4, delim);
        std::getline(ss, q.ans, delim);
        quizes.push_back(q);
    }

    quiz.close();
    return;
  }
  void saveMark(int mark, std::string sap, std::string subject, int total)
  {
    std::ofstream res;
    std::string file = "storage/" + sap + ".csv";
    res.open(file, std::ios::app);
    res << mark << "," << subject << "," << total << std::endl;
    res.close();
    return;
  }
  void attemptQuiz(char delim = ',')
  {
    sub:
    int subNum;
    subjectSelector();
    std::cin >> subNum;
    subNum--;
    if (subNum < 0 || subNum >= subjects.size()) {
      std::cout << "Wrong choice:\n";
      goto sub;
    }
    readQuizDataInStructures(subjects[subNum].name);
    std::random_shuffle ( quizes.begin(), quizes.end() );
    ask:
    int max;
    std::cout << "Enter number of question you want to get: btw 5 to 10: ";
    std::cin >> max;
    if (max < 1 || max > 10) {
      std::cout << "Wrong choice:\n";
      goto ask;
    }
    if (max == quizes.size()) {
      std::cout << "\nNumber of question should be less then total question\n";
      return;
    }
    char o;
    std::string option;
    int mark = 0;
    int total = 0;
    for (int i = 0; i < max; i++) {
      std::cout << i+1 << ": " << quizes[i].question << std::endl;
      std::cout << "a) " << quizes[i].option4 << std::endl;
      std::cout << "b) " << quizes[i].option2 << std::endl;
      std::cout << "c) " << quizes[i].option3 << std::endl;
      std::cout << "d) " << quizes[i].option1 << std::endl;
      std::cin >> o;
      if (o == 'a')
        option = quizes[i].option4;
      else if (o == 'b')
        option = quizes[i].option2;
      else if (o == 'c')
        option = quizes[i].option3;
      else if (o == 'd')
          option = quizes[i].option1;
      else
        option = "null";

      option = lablnet::strtolower(option);
      std::string ans = lablnet::strtolower(quizes[i].ans);
      lablnet::trim(option);
      lablnet::trim(ans);
      if (option != ans) {
        std::cout << "\nSorry your answer is wrong\t correct answer is : " << quizes[i].ans << "\n";
        mark--;
      }
      mark++;
      total++;
    }
    std::cout << "Your mark: " << mark << " out of " << total << std::endl;
    int opt;
    std::cout << "Would you like to save your marks? 0/1: ";
    std::cin >> opt;
    if (opt == 1) {
      std::string sap;
      std::cout << "Enter your SAP id: ";
      std::cin >> sap;
      lablnet::saveMark(mark, sap, subjects[subNum].name, total);
    } else
      return;
  }
} // End lablnet

#endif // QUIZ_H_INCLUDED
