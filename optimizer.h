
#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>
#include <string>

using namespace std;


class Optimizer
{

private:

    vector<string> tacCode;


public:

    Optimizer(vector<string> t);


    void optimize();

};


#endif
