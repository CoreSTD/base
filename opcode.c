#define __STDC_HOSTED__ 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

/* Max Register for the C ABIV Calling Convension */
// MAX_REGISTER is the max of arguments the arch takes for syscalls
#if defined(__i386__)
	#define MAX_REGISTER 6
	#define SYSCALL_REG eax
	#define EXECUTE_SYSCALL "int $0x80"
#elif defined(__x86_64__) || defined(__amd__)
	#define MAX_REGISTER 6
	#define SYSCALL_REG rax
	#define EXECUTE_SYSCALL "syscall"
#elif defined(__riscv)
	#define MAX_REGISTER 8
	#define SYSCALL_REG a7
	#define EXECUTE_SYSCALL "ecall"
#elif defined(__aarch64__)
	#define MAX_REGISTER 8
	#define SYSCALL_REG x8
	#define EXECUTE_SYSCALL "svc #0"
#elif defined(__arm__)
	#define MAX_REGISTER 4
	#define SYSCALL_REG r7
	#define EXECUTE_SYSCALL "svc #0"
#elif defined(_WIN64)
	#define MAX_REGISTER 4
	#define SYSCALL_REG rcx
	#define EXECUTE_SYSCALL "syscall"
#else
	#define MAX_REGISTER 0
	#define SYSCALL_REG 0
	#define EXECUTE_SYSCALL 0
#endif

typedef __int64_t ptr;

typedef struct
{
	ptr 	*base;
	int 	capacity;
} mem_page;

typedef enum
{
	_null_op 	= 0,
	create 		= 1,
	set 		= 2,
	del 		= 4,
	call 		= 5,
	jump 		= 6,
	inc 		= 7,
	dec 		= 8
} x86_64_op;

typedef enum
{
	_nullreg 	= 0,
	_rax 		= 1,
	_rdi		= 2,
	_rsi 		= 3,
	_rdx		= 4,
	_r10 		= 5,
	_r8 		= 6,
	_r9 		= 7,
	_r11		= 8,
	_r12		= 9,
	_r13		= 10,
	_r14		= 11,
	_r15		= 12
} x86_64_registers;

/*

// Features (Memory for the app would be a different region using mmap)

create var, size, 0  			// create new variable with size initialized with 0
set var, size					// set new value to the variable with size
del var							// delete the variable
inc								// Increament
dec								// Decreament
call fn_name					// call function
jmp								// jump to function

call memset ptr, 0, size		// calling a function with arguments

// Example below

section mem:
	char character				// char
	char[1000] buffer, 0		// char array

	int n, 0					// int
	int[100] n, 0				// int array

section code:

_main:
	memset buffer, 0, 10 		// in this case, buffer would just be the ptr address

*/

int main() {
    size_t size = 4096; // one page

    void *mem = mmap(
        NULL,
        size,
        PROT_READ | PROT_WRITE | PROT_EXEC,  // ← executable
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

    if (mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Example: machine code that returns 42 (x86_64)
    unsigned char code[] = {
        0xB8, 0x2A, 0x00, 0x00, 0x00, // mov eax,42
        0xC3                          // ret
    };

    memcpy(mem, code, sizeof(code));

    int (*func)(void) = mem;
    printf("Result: %d\n", func());

    munmap(mem, size);
}
