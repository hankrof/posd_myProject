#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#include <string>
#include <sstream>
#include "term.h"
#include "variable.h"
class Number : public Term
{
public:
    Number(int v) 
        : Term(std::to_string(v))
    {
        _value = v;
    }
    int value() const
    {
        return _value;
    }
    bool match(const Term &term)
    {
        return Term::match(term);
    }
    bool match(Var &var)
    {
        return var.match(*this);
    }
private:
    int _value;
};
#endif
