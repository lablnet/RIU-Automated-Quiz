#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <string>
#include <vector>

// Store dataset for users.
typedef struct {
  int sap;
  std::string name;
  long long int password;
  unsigned short int admin;
} User;
std::vector<User> users;

// Structure to store quizes questions.
typedef struct {
  std::string name;
} Subject;
std::vector<Subject> subjects;

// Structure to store quizes questions.
typedef struct {
  std::string question;
  std::string option1;
  std::string option2;
  std::string option3;
  std::string option4;
  std::string ans;
} Quiz;
std::vector<Quiz> quizes;

// Store the result.
typedef struct {
  int mark;
  std::string subject;
  int total;
} Result;
std::vector<Result> results;

#endif
