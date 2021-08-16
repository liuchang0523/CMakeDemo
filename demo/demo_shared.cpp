#include <iostream>
#include "add.h"

int main(int argc, char** argv)
{
	std::cout << "version:" << getAddVersion() << std::endl;

	int c = myAdd(1, 3);
	std::cout << c << std::endl;

	return 0;
}
