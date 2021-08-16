#include "mul.h"
#include "version.h"

MYDLL int myMul(int a, int b)
{
	return a * b;
}

MYDLL const char* getMulVersion()
{
	return VERSION;
}
