void _test(long a1, long a2, long a3, long a4, long a5, long a6)
{
    (void *)a1;
}

int main()
{
	int n;
	n = 8;
    _test(0, 0, 0, 0, 0, 0);
    return 0;
}
