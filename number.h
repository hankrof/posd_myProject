#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#include <string>
#include <sstream>
#include <iomanip>
#include "term.h"
#include "variable.h"
class Number : public Term
{
public:
    Number(int v) 
    {
        _symbol = std::to_string(v);
    }
    Number(double v)
    {
        std::stringstream ss;
        ss << v;
        ss >> _symbol; 
    }
    std::string symbol() const
    {
        return _symbol;
    }
private:
    std::string _symbol;
};
#endif
