#ifndef mul_h__
#define mul_h__

#if defined WIN32 && defined dll_EXPORTS
# define MYDLL __declspec(dllexport)
#else
# define MYDLL
#endif

MYDLL int myMul(int a, int b);

MYDLL const char* getMulVersion();

#endif // mul_h__
