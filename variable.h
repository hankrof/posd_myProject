#ifndef VARIABLE_H
#define VARIABLE_H
#include "atom.h"
#include <vector>
class Variable : public Term
{
public:
    Variable(std::string s);
    std::string value() const;
    std::string symbol() const;
    bool match(Term &term);
    std::string const _symbol;
private:
    void add_shared_var(Variable *var);
    void instantiate_shared_var(Term *_nvalue);
    Term * _value;
    std::vector<Variable*> _sharedlist;
    bool _instantiated;
};
#endif
