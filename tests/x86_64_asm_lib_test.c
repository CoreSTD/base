/* x86_64 ASM Lib TEST */
long __read__(int fd, char *buffer, int size);
long __write__(int fd, char *buffer, int size);
void __exit__(int code);

void _start()
{
	char BUFF[100];

	for(int i = 0; i < 5; i++)
	{
		__write__(1, "> ", 2);
		int bytes = __read__(0, BUFF, 100);

		if(BUFF[0] == 'q')
			break;

		if(BUFF[0] == 'h' && BUFF[1] == 'i')
			__write__(1, "hi\n", 3);
	}
	__write__(1, "dick\n", 5);
	__exit__(0);
}
