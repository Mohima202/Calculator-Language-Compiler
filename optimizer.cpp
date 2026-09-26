
#include "optimizer.h"
#include <iostream>
#include <sstream>

using namespace std;


Optimizer::Optimizer(vector<string> t)
{
    tacCode = t;
}



void Optimizer::optimize()
{

    cout << "\n========== OPTIMIZATION ==========\n";


    cout << "\nOriginal TAC:\n";


    for(string line : tacCode)
    {
        cout << line << endl;
    }



    vector<string> optimized;


    cout << "\nConstant Folding Applied:\n";



    for(string line : tacCode)
    {

        string result, equal, op;
        int num1, num2;


        stringstream ss(line);



        // Example:
        // t1 = 5 + 3

        ss >> result >> equal >> num1 >> op >> num2;



        if(equal == "=" && op == "+")
        {

            int value = num1 + num2;


            cout << num1
                 << " + "
                 << num2
                 << " -> "
                 << value
                 << endl;



            optimized.push_back(
                result + " = " + to_string(value)
            );

        }

        else
        {
            optimized.push_back(line);
        }


    }



    cout << "\nOptimized TAC:\n";


    for(string line : optimized)
    {
        cout << line << endl;
    }

}
