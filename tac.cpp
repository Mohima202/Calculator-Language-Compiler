
#include "tac.h"
#include <iostream>

using namespace std;


TAC::TAC(vector<Token> t)
{
    tokens = t;
}

void TAC::generate()
{

    cout << "\n========== THREE ADDRESS CODE ==========\n";


    int i = 0;
    int temp = 1;


    while(i < tokens.size())
    {
        if(i+3 < tokens.size() &&
           tokens[i].type == IDENTIFIER &&
           tokens[i+1].type == ASSIGN &&
           tokens[i+2].type == NUMBER &&
           tokens[i+3].type == SEMICOLON)
        {
            string line =
            tokens[i].value + " = " +
            tokens[i+2].value;


            code.push_back(line);


            cout << line << endl;


            i += 4;
            continue;

        }
        if(i+5 < tokens.size() &&
           tokens[i].type == IDENTIFIER &&
           tokens[i+1].type == ASSIGN &&
           (tokens[i+2].type == NUMBER ||
            tokens[i+2].type == IDENTIFIER) &&
           tokens[i+3].type == PLUS &&
           (tokens[i+4].type == NUMBER ||
            tokens[i+4].type == IDENTIFIER) &&
           tokens[i+5].type == SEMICOLON)
        {
            string tempLine =
            "t" + to_string(temp) +
            " = " +
            tokens[i+2].value +
            " + " +
            tokens[i+4].value;


            string assignLine =
            tokens[i].value +
            " = t" +
            to_string(temp);



            code.push_back(tempLine);
            code.push_back(assignLine);



            cout << tempLine << endl;
            cout << assignLine << endl;



            temp++;


            i += 6;
            continue;

        }
        i++;

    }

}



vector<string> TAC::getCode()
{
    return code;
}
