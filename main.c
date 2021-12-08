#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Header.h"
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS_

int main()
{
	FILE* file;
	clock_t t1, t2;
	long int N, i;
	int state=1,sort=0;
	double *WorkMas, *SaveMas;
	N = 0; i = 0;
	setlocale(LC_ALL, "Rus");

	fopen_s(&file, "..\\file.txt", "r");
	fscanf_s(file, "n=%d\n", &N);
	WorkMas = (double*)malloc(N * sizeof(double));
	SaveMas = (double*)malloc(N * sizeof(double));
	for (i = 0; i < N; i++)
	{
		fscanf_s(file, "%lf\n", &WorkMas[i]);
		SaveMas[i] = WorkMas[i];
	}
	fclose(file);

	while (state!=0)
	{
		printf("Если хотите напечатать массив, введите '1'\n");
		printf("Если хотите отсортировать массив, введите '2'\n");
		printf("Если хотите сбросить массив к изначальному виду, введите '3'\n");
		printf("Если хотите Выйти из программы, введите '0'\nВвод:");
		scanf_s("%d", &state);

		if (state == 1)
			PrintMas(N, WorkMas);
		else if (state == 2)
		{
			while ((sort != 1) && (sort != 2) && (sort != 3))
			{
				printf("Какую сортировку провести? Пузырьком-'1', Вставкой-'2', Быструю-'3'\nВвод:");
				scanf_s("%d", &sort);
			}
			if (sort == 1)
			{
				t1 = clock();
				BubbleSort(N, WorkMas);
				t2 = clock();
			}
			if (sort == 2)
			{
				t1 = clock();
				InserSort(N, WorkMas);
				t2 = clock();
			}
			if (sort == 3)
			{
				t1 = clock();
				QuickSort(N, WorkMas);
				t2 = clock();
			}

			fopen_s(&file, "..\\file.txt", "w");
			fprintf(file,"n=%d\n",N);
			for (i = 0; i < N; i++)
				fprintf(file, "%lf\n", WorkMas[i]);
			fclose(file);
			sort = 0;
			printf("Массив отсортирован, время сортировки составило %lf\n", ((double)(t2 - t1)) / CLOCKS_PER_SEC);
		}
		else if (state == 3)
		{
			fopen_s(&file, "..\\file.txt", "w");
			TrowMas(N, SaveMas, WorkMas, file);
			fclose(file);
			printf("Файл был приведён к изначальному виду\n");
		}
		else if (state == 0)
		{
			printf("Программа завершила работу\n");
			break;
		}
		else
			printf("Введите корректные данные\n");
		printf("\n");
	}


	free(WorkMas);
	free(SaveMas);
	return 0;
}