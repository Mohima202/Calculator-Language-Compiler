#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include "lexer.h"
#include <vector>

using namespace std;


class Intermediate
{

private:

    vector<Token> tokens;


public:

    Intermediate(vector<Token> t);

    void generate();

};


#endif
