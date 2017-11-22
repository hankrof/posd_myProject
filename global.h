#ifndef GLOBAL_H
#define GLOBAL_H

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iostream>

#define NONE       (-1) 
#define EOS        (0)
#define NUMBER     (256)
#define ATOM       (257)
#define ATOMSC     (258)
#define VAR        (259)

extern std::vector<std::pair<std::string, int>> symtable;

bool isSpecialCh(char c);
bool symbolExist(std::string s, int & val);
void printSymbolTable();
#endif
