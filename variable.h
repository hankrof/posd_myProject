#ifndef VARIABLE_H
#define VARIABLE_H
#include "atom.h"
#include <vector>
class Variable : public Term
{
public:
    Variable(std::string s) : 
        _symbol(s), _value(this), _instantiated(false)
    {
        
    }
    std::string value() const
    { 
        Variable *var = dynamic_cast<Variable*>(_value);
        if(var)
            return var->_symbol;
        return _value->value();
    }
    std::string symbol() const
    {
        return _symbol;
    }
    bool match(Term &term) 
    {
        Variable *var = dynamic_cast<Variable*>(&term);
        if(var)
        {
            if(!_instantiated)
                _value = var;
            add_shared_var(var);
            if(var->_instantiated)
                instantiate_shared_var(var->_value);
            var->add_shared_var(this);
            if(_instantiated)
                var->instantiate_shared_var(_value);
            return true;
        }
        else if(!_instantiated)
        {
            instantiate_shared_var(&term);
            return true;
        }
        return _value->symbol() == term.symbol();
    }
    std::string const _symbol;
private:
    void add_shared_var(Variable *var)
    {
        _sharedlist.push_back(var);
    }
    void instantiate_shared_var(Term *_nvalue)
    {
        if(_instantiated)
            return;
        _instantiated = true;
        _value = _nvalue;
        for(auto &i : _sharedlist)
        {
            if(i->_sharedlist.size() > 0)
                i->instantiate_shared_var(_value);
        }
    }
//  std::string _value;
    Term * _value;
    std::vector<Variable*> _sharedlist;
    bool _instantiated;
};
#endif
