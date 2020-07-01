#include <string>
#include <unordered_map>
#include "password.h"

namespace lablnet { // lablnet
  long long int hash(std::string const *password)
  {
    long long int hashPassword = std::hash<std::string>{}(*password);
    // Just my own dummy logics to make large number smaller.
    return (hashPassword / (3600 * 24 * 30 * 12) / 92);
  }
  bool verify(std::string const *password, long long int const *hash1)
  {
    long long int hash2 = hash(password);
    if (*hash1 == hash2)
      return true;
    else
      return false;
  }
} // End lablnet
