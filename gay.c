#include <stdio.h>
#include <clibp.h>

typedef struct
{
	int x, y;
} _test;

entry_t entry()
{
	int n = sizeof(_test);
	printi(n), print("\n");
    println("Compiled clib+ with GCC");
    return 0;
}
