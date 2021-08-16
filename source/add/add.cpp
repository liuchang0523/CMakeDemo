#include "add.h"
#include "version.h"

MYDLL int myAdd(int a, int b)
{
	return a + b;
}

MYDLL const char* getAddVersion()
{
	return VERSION;
}
