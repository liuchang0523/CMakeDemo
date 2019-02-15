#include <iostream>
#include "../include/test.h"

int main(int argc, char** argv)
{
    std::cout << "Vresion:" << getProjectVersion() << std::endl;

    int c = myAdd(1, 3);
    std::cout << c << std::endl;

    return 0;
}
