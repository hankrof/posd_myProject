#ifndef VARIABLE_H
#define VARIABLE_H
#include "atom.h"
#include <vector>
class Variable : public Term
{
public:
    Variable(std::string s) : 
        _symbol(s), _instantiated(false)
    {
        
    }
    std::string value() const
    { 
        if(_instantiated)
            return _value;
        return _symbol;
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
            add_shared_var(var);
            var->add_shared_var(this);
            return true;
        }
        else if(!_instantiated)
        {
            instantiate_shared_var(term.value());
            return true;
        }
        return false;
    }
    std::string const _symbol;
private:
    void add_shared_var(Variable *var)
    {
        if(var->_instantiated)
            instantiate_shared_var(var->_value);
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
