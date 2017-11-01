#include "global.h"
std::vector<std::pair<std::string, int>> symtable;
bool isSpecialCh(char c)
{
    return c == '+'
        // || c == '=' // ... the matching operator
        || c == '-'
        || c == '*'
        || c == '/'
        || c == '<'
        || c == '>'
        || c == '.'
        || c == '&'
        || c == '\\'
        || c == '~'
        || c == '^'
        || c == '$'
        || c == '#'
        || c == '@'
        || c == '?'
        || c == ':';
}

bool symbolExist(std::string s, int & val)
{
    bool found = false;
    val = -1;
    std::vector<std::pair<std::string, int>>::iterator it =
        find_if(symtable.begin(), symtable.end(),
                [s](std::pair<std::string, int> ele)
                {
                    return ele.first == s;
                });

    found = symtable.end() != it;
    if (found)
        val = it - symtable.begin();
    return found;
}

