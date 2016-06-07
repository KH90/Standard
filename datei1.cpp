#include <stdio.h>
#include <iostream>
#include <omp.h>
#include <time.h>
#include <cstdlib>
#include "datei1.h"

void mein_print()
{
	printf("Hallo Welt!\n");
}

int mein_prime(int number)
{
	int prime = 2;

	int i;
	int i2;
	#pragma omp parallel for schedule(dynamic) reduction(+:prime) private(i2)
	for (i = 3; i < number; i += 2)
	{
		i2 = 3;
		while (i % i2 != 0)
		{
			i2 += 2;
			if (i == i2)
			{
				prime++;
				break;
			}
		}
	}

	return prime;
}

void mein_prime_ausgabe(int N)
{
	clock_t start, end;
	start = clock();

	int test1 = mein_prime(N);

	end = clock();

	std::cout << "Primzahlen: " << test1 << std::endl;
	printf("Zeit: %.2f\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void mein_bubble_sort(int *N_array, int N)
{
	int i, j;
	int temp;
	int aenderung;

	for(i = N-1; i > 0; i--)
	{
		aenderung = 0;
		for (j = 0; j < i; j++)
		{
			if (N_array[j] > N_array[j + 1])
			{
				temp = N_array[j];
				N_array[j] = N_array[j + 1];
				N_array[j + 1] = temp;
				aenderung = 1;
			}
		}
		if(aenderung == 0)
			break;
	}
}

void mein_array_print(int *N_array, int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("array[%d]: %d\t", i, N_array[i]);
		if (i % 2 == 1)
			printf("\n");
	}
}

void random_array(int *rand_array, int N, int range)
{
	int i;
	srand(time(NULL));
	
	if(range <= 1)
		for (i = 0; i < N; i++)
			rand_array[i] = rand();
	else
		for (i = 0; i < N; i++)
			rand_array[i] = rand() % range;
}