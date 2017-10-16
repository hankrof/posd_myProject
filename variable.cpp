#include "variable.h"
Variable::Variable(std::string s) : 
    _symbol(s), _value(this), _instantiated(false)
{

}
std::string Variable::value() const
{ 
    Variable *var = dynamic_cast<Variable*>(_value);
    if(var)
        return var->_symbol;
    return _value->value();
}
std::string Variable::symbol() const
{
    return _symbol;
}
bool Variable::match(Term &term) 
{
    Variable *var = dynamic_cast<Variable*>(&term);
    if(var)
    {
        if(!_instantiated)
            _value = var->_value;
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
void Variable::add_shared_var(Variable *var)
{
    _sharedlist.push_back(var);
}
void Variable::instantiate_shared_var(Term *_nvalue)
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

