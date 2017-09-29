#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#include <string>
#include <sstream>
#include "term.h"
#include "variable.h"
class Number : public Term
{
public:
    Number(std::string s) 
        : Term(s)
    {
        std::stringstream ss(s);
        ss >> _value;
    }
    int value() const
    {
        return _value;
    }
    bool match(const Term &term)
    {
        return Term::match(term);
    }
    bool match(Variable &var)
    {
        return var.match(*this);
    }
private:
    std::string const _symbol;
    int _value;
};
#endif
