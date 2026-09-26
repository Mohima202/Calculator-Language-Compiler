#include "intermediate.h"
#include <iostream>

using namespace std;


Intermediate::Intermediate(vector<Token> t)
{
    tokens = t;
}



void Intermediate::generate()
{

    cout << "\n========== INTERMEDIATE CODE ==========\n";


    int i = 0;


    while(i < tokens.size())
    {


        /*
            a = 10;
        */

        if(i + 3 < tokens.size() &&
           tokens[i].type == IDENTIFIER &&
           tokens[i+1].type == ASSIGN &&
           tokens[i+2].type == NUMBER &&
           tokens[i+3].type == SEMICOLON)
        {

            cout << "LOAD "
                 << tokens[i+2].value
                 << endl;


            cout << "STORE "
                 << tokens[i].value
                 << endl;


            i += 4;
            continue;
        }

        if(i + 5 < tokens.size() &&
           tokens[i].type == IDENTIFIER &&
           tokens[i+1].type == ASSIGN &&

           (tokens[i+2].type == IDENTIFIER ||
            tokens[i+2].type == NUMBER) &&

           tokens[i+3].type == PLUS &&

           (tokens[i+4].type == IDENTIFIER ||
            tokens[i+4].type == NUMBER) &&

           tokens[i+5].type == SEMICOLON)
        {


            cout << "LOAD "
                 << tokens[i+2].value
                 << endl;


            cout << "ADD "
                 << tokens[i+4].value
                 << endl;


            cout << "STORE "
                 << tokens[i].value
                 << endl;



            i += 6;
            continue;
        }



        i++;

    }

}
