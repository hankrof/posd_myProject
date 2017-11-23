#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <string>
#include "atom.h"

class Struct : public Term
{
public:
    Struct(Atom const &name, std::vector<Term *> args);
    Term * args(int index);
    void setArgs(int index, Term* term); 
    int arity() const;
    Atom const& name() const;
    std::string value() const;
    std::string symbol() const;
    bool match(Term &term);
private:
    Atom const _name;
    std::vector<Term *> _args;
};
#endif
