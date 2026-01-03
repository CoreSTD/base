#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int dick = sysconf(_SC_PAGESIZE);
    printf("%d\n", dick);
    return 0;
}