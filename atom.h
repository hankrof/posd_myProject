#ifndef ATOM_H
#define ATOM_H
#include "term.h"
#include "variable.h"
class Atom : public Term
{
public:
    Atom (std::string s):
        _symbol(s) 
    {

    }  
    bool match(Term &term)
    {
        Variable *var = dynamic_cast<Variable*>(&term);
        if(var)
            return var->match(*this);
        return _symbol == term.symbol();
    }
    std::string symbol() const
    {
        return _symbol;
    }
private:
    std::string _symbol;
};
#endif
