#ifndef ATOM_H
#define ATOM_H
#include "term.h"
class Atom : public Term
{
public:
    Atom (std::string s):
        _symbol(s) 
    {

    }  
    std::string symbol() const
    {
        return _symbol;
    }
private:
    std::string _symbol;
};
#endif
