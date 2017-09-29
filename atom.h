#ifndef ATOM_H
#define ATOM_H
#include <string>
#include "term.h"
class Atom : public Term 
{
public:
    Atom (std::string s) 
        : Term(s) 
    {

    }
    bool match(const Term &term)
    {
        return Term::match(term);
    }
    bool match(Var &var)
    {
        return var.match(*this);
    }
};
#endif
