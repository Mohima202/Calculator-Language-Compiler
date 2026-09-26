
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>
#include <map>
#include <string>

using namespace std;


class SymbolTable
{

private:

    map<string, int> table;


public:

    void insert(string name, int value);

    // For expression like: c = 5 + 6
    void insertExpression(string name, int left, int right, char op);

    bool exists(string name);

    int getValue(string name);

    void print();

};


#endif
