#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <string>
#include "atom.h"

class Struct : public Term
{
public:
    Struct(Atom const &name, std::vector<Term *> args)
        : _name(name), _args(args) 
    {
        
    }
    Term * args(int index)
    {
        return _args[index];
    }
    Atom const& name() const
    {
        return _name;
    }
    std::string value() const
    {
        std::string sym_name(_name.symbol());
        sym_name += '(';
        for(size_t i=0;i<_args.size()-1;i++)
        {
            sym_name += _args[i]->value();
            sym_name += ", ";
        }
        sym_name += _args[_args.size() - 1]->value();
        sym_name += ')'; 
        return sym_name;
    }
    std::string symbol() const
    {
        std::string sym_name(_name.symbol());
        sym_name += '(';
        for(size_t i=0;i<_args.size()-1;i++)
        {
            sym_name += _args[i]->symbol();
            sym_name += ", ";
        }
        sym_name += _args[_args.size() - 1]->symbol();
        sym_name += ')'; 
        return sym_name;
    }
    bool match(Term &term)
    {
        Variable *var = dynamic_cast<Variable*>(&term);
        if(var)
            return var->match(*this);
        return symbol() == term.symbol();
    }
 
private:
    Atom const _name;
    std::vector<Term *> _args;
};
#endif
