#include "parser.h"

Parser::Parser(Scanner const& scanner)
    : _scanner(scanner), _currentToken(NONE), _exprRoot(nullptr) 

{

}
Term* Parser::createTerm()
{
    int token = _scanner.nextToken();
    _currentToken = token;
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
        if(_scanner.currentChar() == '(' ) 
        {
            return structure();
        }
        else
            return atom;
    }
    else if(token == '[')
    {
        return list();
    }
    return nullptr;
}

Term* Parser::structure() 
{
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')

    {
        vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
        _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
        return new Struct(structName, args);
    }
    else 
    {
        throw std::string("unexpected token");
    }
}

void Parser::matchings()
{
    Term *term;
    Node *node;
    _terms.clear();
    _nodes.clear();
    while((term = createTerm()))
    {
        int c = _scanner.currentChar();
        _terms.push_back(term);
        _nodes.push_back(new Node(TERM, term, nullptr, nullptr));
        if(c == '.')
        {
            break;
        }
        else if(c == ',' ||  c == '=' ||  c == ';')
        {
            switch(c)
            {
            case ',':
                node = new Node(COMMA);
                break;
            case '=':
                node = new Node(EQUALITY);
                break;
            case ';':
                node = new Node(SEMICOLON);
                break;
            }
            _nodes.push_back(node);
            _scanner.nextToken();
        }
    }
}

Node* Parser::expressionTree()
{
    //        0      1         2     3
    //SEMICOLON, COMMA, EQUALITY, TERM
    int priority[] = {2, 3, 4}; 
    Node *node;
    std::vector<Node*> postfix;
    std::stack<Node*> stk;
    for(size_t i=0; i<_nodes.size(); i++)
    {
        node = _nodes[i]; 
        if(node->payload == TERM)
            postfix.push_back(node);
        else //For future, if there adds the new operator. Use icp & isp
        {
            while(!stk.empty() && 
                  priority[stk.top()->payload] >= priority[node->payload])
            {
                postfix.push_back(stk.top());
                stk.pop();
            }
            stk.push(node);
        }
    }

    while(!stk.empty())
    {
        postfix.push_back(stk.top());
        stk.pop();
    }
 
    int payload;
    for(size_t i=0; i<postfix.size(); i++)
    {
        node    = postfix[i]; 
        payload = node->payload;
        if(payload == EQUALITY)
        {
            Node *n1, *n2; 
            n1 = stk.top();
            stk.pop();
            n2 = stk.top();
            stk.pop();

            node->left  = n2;
            node->right = n1;
            n2->term->match(*n1->term);

            stk.push(node);
        }
        else if(payload == COMMA)
        {
            Node *n1, *n2; 
            n1 = stk.top();
            stk.pop();
            n2 = stk.top();
            stk.pop();

            node->left  = n2;
            node->right = n1;
 
            stk.push(node);
        }
        else if(payload == TERM)
        {
            stk.push(node);
        }
    }

    _exprRoot = stk.top();
    stk.pop();

    return _nodes.size() ? _exprRoot : nullptr;
}

Term* Parser::list() 
{
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')

    {
        vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
        _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
        return new List(args);
    } else 
    {
        throw std::string("unexpected token");
    }
}

std::vector<Term *>& Parser::getTerms() 
{
    return _terms;
}


void Parser::createTerms()
{
    Term* term = createTerm();
    if(term != nullptr)
    {
        _terms.push_back(term);
        while((_currentToken = _scanner.nextToken()) == ',')  
            _terms.push_back(createTerm());
    }
}

