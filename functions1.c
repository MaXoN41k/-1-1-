#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Header.h"
#include <time.h>

void Hand(int n, FILE* f)
{
	double t;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lf",&t);
		fprintf(f, "%lf\n",t);
	}
}

void Ran(int n, int min, int max, FILE* f)
{
	double t;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		t = (((double)rand()) / RAND_MAX * (max - min) + min);
		fprintf(f, "%lf\n", t);
	}
}
