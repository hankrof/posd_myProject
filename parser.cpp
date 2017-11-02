#include "parser.h"
Parser::Parser(Scanner scanner)
    : _scanner(scanner), _currentToken(NONE) 
{

}
Term* Parser::createTerm()
{
    int token = _scanner.nextToken();
    if(token == VAR)
    {
        return new Variable(symtable[_scanner.tokenValue()].first);
    }
    else if(token == NUMBER)
    {
        return new Number(_scanner.tokenValue());
    }
    else if(token == ATOM || token == ATOMSC)
    {
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if((token = _scanner.nextToken()) == '(') 
        {
            vector<Term*> terms;
            terms = getArgs();
            if(!terms.empty() && _currentToken == ')')
                return new Struct(*atom, terms);
            else if(terms.empty())
                return new Struct(*atom, terms);
            else
                throw std::string("unexpected token");
        }
        else
            _scanner.rewind(1);
        return atom;
    }
    else if(token == '[')
    {
        vector<Term*> terms;
        terms = getArgs();
        if(!terms.empty() && _currentToken == ']')
            return new List(terms);
        else if(terms.empty())
            return new List(terms);
        else
            throw std::string("unexpected token");
    }
    return NULL;
}
std::vector<Term*> Parser::getArgs()
{
    Term* term = createTerm();
    vector<Term*> args;
    if(term)
    {
        args.push_back(term);
        while((_currentToken = _scanner.nextToken()) == ',') 
        {
            args.push_back(createTerm());
        }
    }
    return args;
}

