#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	long int N, i;
	long double min, max, pr, sum;
	double* masZn;
	int* masOst;
	setlocale(LC_ALL, "Rus");
	min = 0.0; max = 0.0; N = 0; sum = 0;

	printf("¬ведите количество случайных чисел ");
	scanf_s("%d", &N);
	printf("¬ведите минимум диапазона ");
	scanf_s("%lf", &min);
	printf("¬ведите максимум диапазона ");
	scanf_s("%lf", &max);

	if ((N <= 0) || (min <= 0.0) || (max <= 0.0) || (max <= min))
	{
		printf("ќшибка, введите коректные данные");
		return 0;
	}

	masZn = (double*)malloc(N * sizeof(double));
	masOst = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
	{
		masZn[i] = (((double)rand()) / RAND_MAX * (max - min) + min);
		pr = (masZn[i] - (int)masZn[i]) * 1000000;
		if (pr == 0)
			masOst[i] = 0;
		else
		{
			masOst[i] = (int)pr;
			while (masOst[i] % 10 == 0)
				masOst[i] = masOst[i] / 10;
		}
	}

	for (i = 0; i < N; i++)
		if (masOst[i] < N)
		{
			sum = sum - masZn[masOst[i]];
			masZn[masOst[i]] = 0.0;
		}

	for (i = 0; i < N; i++)
		sum = sum + masZn[i];
	printf("»тогова€ сумма равна %lf ", sum);
	free(masZn);
	free(masOst);
	return 0;
}