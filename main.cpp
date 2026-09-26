#include <iostream>
#include <vector>
#include <string>

#include "lexer.h"
#include "symboltable.h"
#include "parser.h"
#include "semantic.h"
#include "intermediate.h"
#include "tac.h"
#include "optimizer.h"

using namespace std;

int main()
{
    string input;
    string line;
    int n;


    cout << "========== Calculator Language COMPILER ==========\n";

    cout << "How many lines? ";
    cin >> n;
    cin.ignore();


    cout << "\nEnter Source Code:\n";


    for(int i = 0; i < n; i++)
    {
        getline(cin,line);
        input += line + " ";
    }



    // ==========================
    // 1. Lexical Analysis
    // ==========================

    Lexer lexer(input);

    vector<Token> tokens = lexer.tokenize();


    lexer.printTokens(tokens);
    // ==========================
    // 2. Syntax Analysis
    // ==========================

    Parser parser(tokens);


    if(!parser.checkSyntax())
    {
        cout << "Syntax Error!\n";
        return 0;
    }
    // ==========================
    // 3. Symbol Table
    // ==========================

    SymbolTable st;


    for(int i=0; i<tokens.size(); i++)
    {
        if(i+3 < tokens.size() &&
           tokens[i].type == IDENTIFIER &&
           tokens[i+1].type == ASSIGN &&
           tokens[i+2].type == NUMBER &&
           tokens[i+3].type == SEMICOLON)
        {

            st.insert(
                tokens[i].value,
                stoi(tokens[i+2].value)
            );

        }
        else if(i+5 < tokens.size() &&
                tokens[i].type == IDENTIFIER &&
                tokens[i+1].type == ASSIGN &&
                tokens[i+2].type == IDENTIFIER &&
                tokens[i+3].type == PLUS &&
                tokens[i+4].type == IDENTIFIER &&
                tokens[i+5].type == SEMICOLON)
        {

            int left = st.getValue(tokens[i+2].value);

            int right = st.getValue(tokens[i+4].value);


            st.insertExpression(
                tokens[i].value,
                left,
                right,
                '+'
            );

        }
        else if(i+5 < tokens.size() &&
                tokens[i].type == IDENTIFIER &&
                tokens[i+1].type == ASSIGN &&
                tokens[i+2].type == NUMBER &&
                tokens[i+3].type == PLUS &&
                tokens[i+4].type == NUMBER &&
                tokens[i+5].type == SEMICOLON)
        {

            st.insertExpression(
                tokens[i].value,
                stoi(tokens[i+2].value),
                stoi(tokens[i+4].value),
                '+'
            );

        }

    }



    st.print();



    // ==========================
    // 4. Semantic Analysis
    // ==========================


    Semantic semantic(tokens,&st);

    semantic.checkSemantic();



    // ==========================
    // 5. Intermediate Code Generation
    // ==========================


    Intermediate ic(tokens);

    ic.generate();


// ==========================
// 6. Three Address Code
// ==========================


TAC tac(tokens);

tac.generate();


vector<string> tacCode = tac.getCode();



// ==========================
// 7. Code Optimization
// ==========================


Optimizer optimizer(tacCode);

optimizer.optimize();


    cout<<"\n========== COMPILATION FINISHED ==========\n";


    return 0;

}
