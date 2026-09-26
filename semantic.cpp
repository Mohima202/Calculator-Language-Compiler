
#include "semantic.h"
#include <iostream>

using namespace std;

Semantic::Semantic(vector<Token> t, SymbolTable *table)
{
    tokens = t;
    st = table;
}

bool Semantic::checkSemantic()
{
    cout << "\n========== SEMANTIC ANALYSIS ==========\n";

    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i].type == IDENTIFIER)
        {
            // Assignment-এর left side skip
            if(i + 1 < tokens.size() &&
               tokens[i+1].type == ASSIGN)
            {
                continue;
            }

            if(!st->exists(tokens[i].value))
            {
                cout << "Semantic Error : Undeclared Variable -> "
                     << tokens[i].value << endl;

                return false;
            }
        }
    }

    cout << "No Semantic Error.\n";

    return true;
}
