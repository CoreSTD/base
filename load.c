#undef _STDIO_H

void *print_(int fd, char *v, int sz, int sys) {
	register long b asm("rax") = sys;
	asm("syscall");
}

void _start()
{
		print_(1, "dick\n", 5, 1);
		print_(0, 0, 0, 60);
}

