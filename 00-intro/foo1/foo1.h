#ifdef WIN32
#  define DECL_EXPORT     __declspec(dllexport)
#  define DECL_IMPORT     __declspec(dllimport)
#else
#  define DECL_EXPORT
#  define DECL_IMPORT
#endif

#ifdef FOO1_LIBRARY
#  define LIBFOO1SHARED_EXPORT DECL_EXPORT
#else
#  define LIBFOO1SHARED_EXPORT DECL_IMPORT
#endif

#include <program.h>
void LIBFOO1SHARED_EXPORT foo1();
