#ifndef LINUX_H_INCLUDED
#define LINUX_H_INCLUDED

// Include required header file.
#include <string>
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

namespace lablnet { // lablnet
  int getch() {
      int ch;
      struct termios t_old, t_new;

      tcgetattr(STDIN_FILENO, &t_old);
      t_new = t_old;
      t_new.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

      ch = getchar();

      tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
      return ch;
  }
  std::string getpass(const char *prompt, bool show_asterisk = true)
  {
    const char BACKSPACE = 127;
    const char RETURN = 10;
    std::string password;
    unsigned char ch = 0;

    std::cout << prompt << std::endl;

    while((ch=getch()) != RETURN)
      {
         if(ch==BACKSPACE)
           {
              if(password.length() != 0)
                {
                   if(show_asterisk)
                   std::cout << "\b \b";
                   password.resize(password.length() - 1);
                }
           }
         else
           {
               password += ch;
               if(show_asterisk)
                   std::cout << '*';
           }
      }
    std::cout << std::endl;
    return password;
  }
} // End lablnet
#endif // LINUX_H_INCLUDED
