#include <iostream>
#include "mul.h"

int main(int argc, char** argv)
{
	std::cout << "version:" << getMulVersion() << std::endl;

	int c = myMul(1, 3);
	std::cout << c << std::endl;

	return 0;
}
