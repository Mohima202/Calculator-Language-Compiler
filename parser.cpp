
#include "parser.h"
#include <iostream>

using namespace std;

Parser::Parser(vector<Token> t)
{
    tokens = t;
}

bool Parser::checkSyntax()
{
    cout << "\n========== SYNTAX ANALYSIS ==========\n";
    for(int i = 0; i < tokens.size()-1; i++)
    {
        if(tokens[i].type == ASSIGN &&
           tokens[i+1].type == SEMICOLON)
        {
            cout << "Syntax Error : Missing value after '='\n";
            return false;
        }
    }
    for(int i = 0; i < tokens.size()-1; i++)
    {
        if((tokens[i].type == PLUS ||
            tokens[i].type == MINUS ||
            tokens[i].type == MULTIPLY ||
            tokens[i].type == DIVIDE)
            &&
            (tokens[i+1].type == SEMICOLON ||
             tokens[i+1].type == END_OF_FILE))
        {
            cout << "Syntax Error : Missing operand.\n";
            return false;
        }
    }
    if(tokens[tokens.size()-2].type != SEMICOLON)
    {
        cout << "Syntax Error : Missing ';'\n";
        return false;
    }
    cout << "No Syntax Error.\n";
    return true;
}
