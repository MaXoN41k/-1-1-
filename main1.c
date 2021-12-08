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

	printf("Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ");
	scanf_s("%d", &n);
	fprintf_s(file,"n=%d\n", n);
	printf("Åñëè õîòèòå çàïîëíèòü ìàññèâ âðó÷íóþ, íàæìèòå '1', åñëè ñëó÷àéíûìè ÷èñëàìè, òî íàæìèòå íà ëþáóþ äðóãóþ öèôðó");
	scanf_s("%d", &state);
	if (state == 1)
		Hand(n,file);
	else
	{
		printf("Ââåäèòå ìàêñèìàëüíîå çíà÷åíèå ÷èñëà");
		scanf_s("%lf", &max);
		printf("Ââåäèòå ìèíèìàëüíîå çíà÷åíèå ÷èñëà");
		scanf_s("%lf", &min);
		Ran(n,min,max,file);
	}

	fclose(file);
	return 0;
}
