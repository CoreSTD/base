#include "../../headers/clibp.h"

i32 is_i32_valid(i32 num)
{
    return (num < -0x80000000 || num > 0x7FFFFFFF);
}

i32 count_int_digits(i32 num) {
    int n = num;
    if(n == 0) return 1;
    if(n < 0) n = -n;

    int count = 0;
    while(n > 0) {
        n /= 10;
        count++;
    }

    return count;
}