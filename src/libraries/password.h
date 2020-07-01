#ifndef PASSWORD_H_INCLUDED
#define PASSWORD_H_INCLUDED

// Include required header file.
#include <string>
#include "password.cpp"

namespace lablnet { // lablnet
  long long int hash(std::string const *password);
  bool verify(std::string const *password, long long int const *hash1);
} // End lablnet

#endif // PASSWORD_H_INCLUDED
