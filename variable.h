#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include "term.h"
class Var : public Term
{
public:
    Var(std::string s)
        : Term(s) , _assignable(true)
    {

    }
    std::string value()
    {
        return _value; 
    }
    bool isConstant() const
    {
        return !_assignable;
    }
    bool match(const Term &term)
    {
        bool ret = term.symbol() == _value ||
                   _assignable;
        if(_assignable)
        {
            _value = term.symbol();
            _assignable = false;
        }
        return ret;
    }
private:
    std::string _value;
    bool _assignable;
};

#endif
