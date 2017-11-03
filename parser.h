#ifndef PARSER_H
#define PARSER_H

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "number.h"
#include "struct.h"

class Parser
{
public:
    Parser(Scanner &scanner);
    Term* createTerm();
    std::vector<Term*> getArgs();
private:
    Scanner _scanner;
    int _currentToken;
};
#endif
