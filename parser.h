
#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <vector>

using namespace std;

class Parser
{
private:
    vector<Token> tokens;

public:
    Parser(vector<Token> t);

    bool checkSyntax();
};

#endif
