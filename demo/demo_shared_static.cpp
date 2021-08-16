#include <iostream>
#include "mul.h"
#include "add.h"

int main(int argc, char** argv)
{
	std::cout << "version:" << getAddVersion() << std::endl;

	int c = myMul(1, 3);
	std::cout << c << std::endl;

	int d = myAdd(1, 3);
	std::cout << d << std::endl;

	return 0;
}
