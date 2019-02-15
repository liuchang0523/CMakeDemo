#include <iostream>
#include "version.h"
#include "../include/test.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Vresion:" << getProjectVersion() << endl;
    //TODO:你的代码
    cout << "Hello World!" << endl;

    return 0;
}

MYDLL int myAdd(int a, int b)
{
    return a + b;
}

MYDLL const char* getProjectVersion()
{
    return VERSION;
}
