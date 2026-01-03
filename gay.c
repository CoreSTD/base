/*
    clib+ - C supported script.

  2 entry point, 1 for each compiler support

  // gcc test.c -o test -lclibp
  - C       main()

  // gcc_clibp test.c -o test
  - clib+   entry()
*/
#include <stdio.h>

#define __CLIBP__
#include <clibp.h>
#include <asm.h>

#include <allocator.h>

/* gcc_clibp */
entry_t entry()
{
	println("Attempting to init heap...");
    
	HEAP_DEBUG = 1;
    set_heap_sz(_LARGE_MEM_SZ_);
	init_mem();

    
	print("Heap: "), printi(__is_heap_init__()), 
    print(": "), printi(__get_total_mem_used__()), 
    print(":"), _printi(_HEAP_PAGE_SZ_), print("\n");

	str n = allocate(0, 10);
	if(n == NULL) println("ERROR ALLOCATING\n");

    print("Heap: "), printi(__is_heap_init__()), 
    print(": "), _printi(__get_total_mem_used__()), 
    print(":"), _printi(_HEAP_PAGE_SZ_), print("\n");

    println("Compiled with CLIBP");
    return 0;
}

/* gcc */
int main()
{
    printf("Compiled with GCC\n");
    return 0;
}
