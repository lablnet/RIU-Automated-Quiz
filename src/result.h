#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

// Include required header file.
#include "user.h"

namespace lablnet { // lablnet
  void readResultInStructure(std::string sap, char delim = ',')
  {
    std::ifstream res;
    std::string file = "storage/" + sap + ".csv";
    res.open(file);
    if (!res)
    {
        std::cout << "No record found\n";
        return;
    }
    std::string line;
    while (std::getline(res, line))
    {
        std::istringstream ss(line);
        Result result;
        ss >> result.mark; ss.ignore(10, delim);
        std::getline(ss, result.subject,delim);
        ss >> result.total; ss.ignore(10, delim);
        results.push_back(result);
    }
    res.close();
    return;
  }
  void searchResult() {
    std::string sap;
    std::cout << "Enter SAP ID of student: ";
    std::cin >> sap;

    readResultInStructure(sap);
    std::cout <<  std::setw(5)  << "Name"
         << std::setw(15)  << "Mark"
         << std::setw(20) << "Subject"
         << std::setw(25)  << "Total Quiz Mark"
         << '\n';
    for (int i = 0; i < results.size(); i++)
        std::cout << std::setw(5) << lablnet::getNameBySap(std::stoi(sap))
             << std::setw(15)  << results[i].mark
             << std::setw(20) << results[i].subject
             << std::setw(25) << results[i].total
             << '\n';
  }
} // End lablnet

#endif // RESULT_H_INCLUDED
