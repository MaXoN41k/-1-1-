#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Header.h"

void PrintMas(int l, double* mas)
{
	int i;
	for (i = 0; i < l; i++)
		printf("mas[%d]==%.3lf\n", i, mas[i]);
}

void TrowMas(int l, double* masS, double* masW, FILE* f)
{
	int i;
	fprintf_s(f,"n=%d\n",l);
	for (i = 0; i < l; i++)
	{
		fprintf(f,"%lf\n",masS[i]);
		masW[i] = masS[i];
	}
}

void BubbleSort(int l, double* mas)
{
	int i, j;
	double tmp=0.0;

	for (i=0;i<l;i++)
		for (j=0;j<l-i-1;j++)
			if (mas[j] > mas[j+1])
			{
				tmp = mas[j];
				mas[j] = mas[j+1];
				mas[j+1] = tmp;
			}
}

void InserSort(int l, double* mas)
{
	int i, j;
	double tmp;

	for (i = 0; i < l; i++)
	{
		tmp = mas[i];
		for (j = i - 1; j >= 0; j--)
			if (mas[j] > tmp)
				mas[j + 1] = mas[j];
			else
				break;
		mas[j + 1] = tmp;
	}
}

void qSort(double* mas, int l, int u)
{
	int i = l;
	int j = u;
	double tmp = 0;
	double x = mas[(int)((l + u) / 2)];

	do
	{
		while (mas[i] < x)
			++i;
		while (mas[j] > x)
			--j;

		if (i <= j)
		{
			tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i < j);
	if (l < j)
		qSort(mas, l, j);
	if (i < u)
		qSort(mas, i, u);
}

void QuickSort(int l, double* a)
{
	qSort(a, 0, l - 1);
}
