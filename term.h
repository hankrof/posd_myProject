#ifndef TERM_H
#define TERM_H

#include <string>

class Term
{
public:
    virtual std::string symbol() const = 0;
    virtual std::string value() const
    {
        return symbol();
    }
    virtual bool match(Term &term)
    {
        return symbol() == term.symbol();
    }
};

#endif
