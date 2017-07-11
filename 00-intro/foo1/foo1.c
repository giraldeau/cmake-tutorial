#include <stdlib.h>
#include <stdio.h>
#include "foo1.h"

#ifdef CONFIG_FOO1
void LIBFOO1SHARED_EXPORT foo1()
{
    printf("foo1 %s\n", HELLO_VERSION);
}
#else
void LIBFOO1SHARED_EXPORT foo1()
{
}
#endif
