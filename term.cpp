#include "term.h"
#include "iterator.h"
std::string Term::value() const
{
    return symbol();
}

Iterator<Term*>* Term::createIterator()
{
    return new NullIterator<Term*>(this);
}

Iterator<Term*>* Term::createDFSIterator()
{
    return new NullIterator<Term*>(this);
}

Iterator<Term*>* Term::createBFSIterator()
{
    return new NullIterator<Term*>(this);
}
