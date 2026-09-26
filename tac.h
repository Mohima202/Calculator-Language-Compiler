
#ifndef TAC_H
#define TAC_H

#include "lexer.h"
#include <vector>
#include <string>

using namespace std;


class TAC
{
private:

    vector<Token> tokens;
    vector<string> code;


public:

    TAC(vector<Token> t);


    void generate();


    vector<string> getCode();

};


#endif
