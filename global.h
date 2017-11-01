#ifndef GLOBAL_H
#define GLOBAL_H

#include <algorithm>
#include <string>
#include <vector>

const int NONE = -1; // no tokenValue
// tokens return by the scanner
const int EOS = '\0';
const int NUMBER = 256;
const int ATOM = 257;
const int ATOMSC = 258;
const int VAR = 259;
extern std::vector<std::pair<std::string, int>> symtable;
bool isSpecialCh(char c);
bool symbolExist(std::string s, int & val);

#endif
