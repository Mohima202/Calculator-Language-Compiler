
#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "lexer.h"
#include "symboltable.h"
#include <vector>

using namespace std;

class Semantic
{
private:
    vector<Token> tokens;
    SymbolTable *st;

public:
    Semantic(vector<Token> t, SymbolTable *table);

    bool checkSemantic();
};

#endif
