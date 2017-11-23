#ifndef LIST_H
#define LIST_H

#include "term.h"
#include "variable.h"

#include <vector>
#include <memory>

using std::vector;

class List : public Term
{
public:
    List();
    List(vector<Term *> const & elements);
    Term* head() const; 
    List* tail() const;
    std::string symbol() const;
    std::string value() const;
    bool match(Term &term);
private:
    bool matchListDiffVar(List *list); 
    vector<Term*> _elements;
};
#endif

