#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED

#include <string>
#include <algorithm>
#include <cctype>
#include <locale>

namespace lablnet
{ //lablnet

  // trim from start (in place)
  static inline void ltrim(std::string &s) {
      s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
          return !std::isspace(ch);
      }));
  }

  // trim from end (in place)
  static inline void rtrim(std::string &s) {
      s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
          return !std::isspace(ch);
      }).base(), s.end());
  }

  // trim from both ends (in place)
  static inline void trim(std::string &s) {
      ltrim(s);
      rtrim(s);
  }
	std::string strtoupper(std::string str)
	{
		int i = 0;
		while (str[i] != '\0') {
			if(str[i] >= 97 && str[i] <= 122) {
				str[i] = str[i] - 32;
		    }
		    i = i + 1;
		}

		return str;
	}

	std::string strtolower(std::string str)
	{
		int i = 0;
		while (str[i] != '\0') {
			if(str[i] >= 65 && str[i] <= 96) {
				str[i] = str[i] + 32;
		    }
		    i = i + 1;
		}

		return str;
	}
} //lablnet


#endif
