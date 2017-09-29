#ifndef TERM_H
#define TERM_H
class Term
{
public:
    Term(std::string s)
        : _symbol(s)
    {

    }
    std::string symbol() const
    {
        return _symbol;
    }
    virtual bool match(const Term &term)
    {
        return _symbol == term._symbol;
    }
private:
    std::string const _symbol;
};
#endif
