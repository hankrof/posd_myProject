#include "number.h"
Number::Number(int v) 
{
    _symbol = std::to_string(v);
}
Number::Number(double v)
{
    std::stringstream ss;
    ss << v;
    ss >> _symbol; 
}
bool Number::match(Term &term)
{
    Variable *var = dynamic_cast<Variable*>(&term);
    if(var)
        return var->match(*this);
    return _symbol == term.symbol();
}
std::string Number::symbol() const
{
    return _symbol;
}


