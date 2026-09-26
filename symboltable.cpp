
#include "symboltable.h"
#include <iostream>

using namespace std;


void SymbolTable::insert(string name, int value)
{
    table[name] = value;
}


void SymbolTable::insertExpression(string name, int left, int right, char op)
{
    int result = 0;


    switch(op)
    {
        case '+':
            result = left + right;
            break;

        case '-':
            result = left - right;
            break;

        case '*':
            result = left * right;
            break;

        case '/':
            if(right != 0)
                result = left / right;
            break;
    }


    table[name] = result;
}



bool SymbolTable::exists(string name)
{
    return table.find(name) != table.end();
}



int SymbolTable::getValue(string name)
{
    return table[name];
}



void SymbolTable::print()
{
    cout << "\n========== SYMBOL TABLE ==========\n";


    if(table.empty())
    {
        cout << "Symbol Table is Empty.\n";
        return;
    }


    cout << "Variable\tValue\n";


    for(auto x : table)
    {
        cout << x.first
             << "\t\t"
             << x.second
             << endl;
    }
}
