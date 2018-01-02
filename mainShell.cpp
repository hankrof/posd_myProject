#include "parser.h"
#include "shell.h"
using namespace std;
int main(int argc, char **argv)
{
  PrologShell shell;
  while(1)
  {
    char c;
    std::string input;
    input.clear();
    cout << "?- ";
    while(c = getchar())
    {
      if(!isspace(c))
        input.push_back(c);
      if(c == '\n')
        cout << "|   ";
      if(c == '.')
      {
        getchar(); //pop the final '\n'
        break;
      }
    }
    if(input == "halt.")
      break;
    try
    {
      std::cout << shell.execute(input) << std::endl;
    }
    catch(std::string s)
    {
      std::cout << s << std::endl;
    }
  }

  return 0;
}
