#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Header.h"
#include <time.h>

int main()
{
	FILE *file;
	long int n = 0;
	int state = 0;
	double min=0, max=0;
	setlocale(LC_ALL, "Rus");

	fopen_s(&file, "..\\file.txt", "w");

	printf("Введите количество элементов");
	scanf_s("%d", &n);
	fprintf_s(file,"n=%d\n", n);
	printf("Если хотите заполнить массив вручную, нажмите '1', если случайными числами, то нажмите на любую другую цифру");
	scanf_s("%d", &state);
	if (state == 1)
		Hand(n,file);
	else
	{
		printf("Введите максимальное значение числа");
		scanf_s("%lf", &max);
		printf("Введите минимальное значение числа");
		scanf_s("%lf", &min);
		Ran(n,min,max,file);
	}

	fclose(file);
	return 0;
}