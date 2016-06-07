#include <stdlib.h>

int* generate_fibonacci(int N) 
{
	int *fib_array;
	fib_array = (int*)malloc(sizeof(int)*N);

	if (N < 2)
	{
		N = 2;
	}

	fib_array[0] = 1;
	fib_array[1] = 1;

	int i;
	if (N > 2)
	{
		for (i = 2; i < N; i++)
		{
			fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
		}
	}

	return fib_array;
}