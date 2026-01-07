#define STR_H
#include "../headers/clibp.h"
#include "../headers/asm.h"

int __CLIBP_DEBUG__ = 0;
fn __exit(i32 code)
{
	__syscall(60, code, 0, 0, -1, -1, -1);
}

int get_input(string dest, i32 count) {
	char BUFFER[count];
	__syscall(_SYS_READ, 0, (long)BUFFER, count, -1, -1, -1);
	register long bytes_read asm("rax");
	mem_cpy(dest, BUFFER, count);

	return bytes_read;
}

fn ptr_to_str(ptr p, string out)
{
    static const char hex[] = "0123456789abcdef";
    uintptr_t v = (uintptr_t)p;

    out[0] = '0';
    out[1] = 'x';

    for (int i = (sizeof(uintptr_t) * 2) - 1; i >= 0; i--) {
        out[2 + ((sizeof(uintptr_t) * 2 - 1) - i)] =
            hex[(v >> (i * 4)) & 0xF];
    }

    out[2 + sizeof(uintptr_t) * 2] = '\0';
}

fn print_sz(const string buffer, i32 sz)
{
	__syscall(_SYS_WRITE, 1, (long)buffer, sz, 0, 0, 0);
}

fn printc(const char ch)
{
	char BUFF[2] = {0};
	BUFF[0] = ch;
	print(BUFF);
}

fn printi(i32 num)
{
	char BUFF[5] = {0};
	BUFF[0] = '0' + num;
	print(BUFF);
}

fn _printi(int num)
{
	if(num == 0)
	{
		print("0");
		return;
	}

	int temp = num, c = 0;
	char BUFF[500] = {0};
	while(temp)
	{
		BUFF[c++] = '0' + (temp % 10);
		temp /= 10;
	}

	for(int i = 0; i < c; i++)
	{
		char t = BUFF[i], n = BUFF[--c];
		BUFF[i] = n;
		BUFF[c] = t;
	}

	print(BUFF);
}

fn print(const string buff)
{
	__syscall(1, 1, (unsigned long)buff, str_len(buff), -1, -1, -1);
}

fn println(const string buff)
{
	__syscall(1, 1, (unsigned long)buff, str_len(buff), -1, -1, -1);
	__syscall(1, 1, (unsigned long)"\n", 1, -1, -1, -1);
}

ptr to_heap(ptr p, i32 sz)
{
	ptr pointer = allocate(0, sz);
	mem_cpy(pointer, p, sz);

	((string)pointer)[sz] = '\0';
	return pointer;
}
