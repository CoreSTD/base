#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>


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