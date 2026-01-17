#include <stdio.h>
#include <clibp.h>

heap_t OLD_HEAP = NULL;

int entry(int argc, string argv[]) {
	_printi(argc), print(": "), println(argv[0]);
	set_heap_debug();
	OLD_HEAP = _HEAP_;
	init_mem();


	char BUFF[1024];
	__sprintf(BUFF, "Old: %p -> New: %p", OLD_HEAP, _HEAP_);

	println(BUFF);
	uninit_mem();
	_HEAP_ = OLD_HEAP;
    return 0;
}

int main() {
	printf("Hi from GCC with clib+\n");
}
