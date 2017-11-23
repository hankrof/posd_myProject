#include "global.h"
std::vector<std::pair<std::string, int>> symtable;
bool isSpecialCh(char c)
{
  return c == '+'
      // || c == '=' // ... the matching operator
         || c == '-'
         || c == '*'
         || c == '/'
         || c == '<'
         || c == '>'
         || c == '.'
         || c == '&'
         || c == '\\'
         || c == '~'
         || c == '^'
         || c == '$'
         || c == '#'
         || c == '@'
         || c == '?'
         || c == ':';
}

bool symbolExist(std::string s, int & val)
{
    bool found = false;
    val = -1;
    std::vector<std::pair<std::string, int>>::iterator it =
        find_if(symtable.begin(), symtable.end(),
                [s](std::pair<std::string, int> ele)
                {
                    return ele.first == s;
                });
    found = symtable.end() != it;
    if (found)
        val = it - symtable.begin();
    return found;
}
    
bool termExist(Context *context, std::string s, Term **term)
{
    bool found = false;
    *term = nullptr;
    std::vector<std::pair<std::string, Term*>>::iterator it =
        find_if(context->begin(), context->end(),
                [s](std::pair<std::string, Term*> ele)
                {
                    return ele.first == s;
                });
    found = context->end() != it;
    if (found)
        *term = it->second;
    return found;
}

void termAddToContext(Context *context, Term &term)
{
    Struct *s = dynamic_cast<Struct*>(&term);
    List   *l = dynamic_cast<List*>(&term);    
    Term   *t;
    if(s)
    {
        for(int i=0;i<s->arity();i++) 
        {
            t = s->args(i);
            if(!termExist(context, t->symbol(), &t))
                termAddToContext(context, *s->args(i));
            else
            {
                
            }
        }
    }
    else if(l)
    {
        
    }
    context->push_back(std::pair<std::string, Term*>(term.symbol(), &term));
}

void resetTerm(Term *term)
{
    /*
    Atom   *atom;
    Struct *strt;
    List   *list;
    Number *number;
    Variable *variable;
    atom     = dynamic_cast<Atom*>    (term);
    strt     = dynamic_cast<Struct*>  (term);
    list     = dynamic_cast<List*>    (term);
    number   = dynamic_cast<Number*>  (term);
    variable = dynamic_cast<Variable*>(term);
    if(atom)
    {
        *term = Atom(atom->symbol());
    }
    else if(strt)
    {
        Term *t;
        for(int i=0;i<strt->arity();i++)
        {
            if((t = strt->args(i)))
                resetTerm(t);
        }
    }
    else if(list)
    {
        //not implemented yet.
    }
    else if(number)
    {
        *term = Number(number->symbol());
    }
    else if(variable)
        *variable = Variable(variable->symbol());
    */
}

Term* cloneAndResetTerm(Term *term)
{
    Atom   *atom;
    Struct *strt;
    List   *list;
    Number *number;
    Variable *variable;
    atom     = dynamic_cast<Atom*>    (term);
    strt     = dynamic_cast<Struct*>  (term);
    list     = dynamic_cast<List*>    (term);
    number   = dynamic_cast<Number*>  (term);
    variable = dynamic_cast<Variable*>(term);
    if(atom)
        return atom;
    else if(strt)
    {
        Term *t;
        vector<Term*> struct_args;
        for(int i=0;i<strt->arity();i++)
        {
            if((t = strt->args(i)))
            {
                t = cloneAndResetTerm(t);
                struct_args.push_back(t);
            }
            else
                return nullptr;
        }
        return new Struct(strt->name(), struct_args);
    }
    else if(list)
    {
        //not implemented yet.
        return nullptr;
    }
    else if(number)
        return number;
    else if(variable)
    {
        return new Variable(variable->symbol());
    }
    else
        return nullptr;
}

void printSymbolTable()
{
    for(size_t i=0;i<symtable.size();i++)
    {
        printf("[%zd] -> %s, %d\n", i, symtable[i].first.c_str(), symtable[i].second);
    }
}
