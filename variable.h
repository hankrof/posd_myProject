#ifndef VARIABLE_H
#define VARIABLE_H
#include "atom.h"
#include <vector>
class Variable : public Term
{
public:
    Variable(std::string s) : 
        _symbol(s), _value(s), _instantiated(false)
    {
        
    }
    std::string value() const
    { 
        return _value;
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
                _value = var->_symbol;
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
            instantiate_shared_var(term.value());
            return true;
        }
        return _value == term.symbol();
    }
    std::string const _symbol;
private:
    void add_shared_var(Variable *var)
    {
        _sharedlist.push_back(var);
    }
    void instantiate_shared_var(std::string _nvalue)
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
    std::string _value;
    std::vector<Variable*> _sharedlist;
    bool _instantiated;
};
#endif
