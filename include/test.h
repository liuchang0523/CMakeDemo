#ifndef test_h__
#define test_h__

#if defined WIN32 && defined dll_EXPORTS
# define MYDLL __declspec(dllexport)
#else
# define MYDLL
#endif

MYDLL int myAdd(int a, int b);

MYDLL const char* getProjectVersion();

#endif // test_h__
