// Lab5_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "rus");
	int n, m, temp;

	printf("Введите кол-во строк N = ");
	scanf_s("%d", &n);
	printf("Введите кол-во столбцов M = ");
	scanf_s("%d", &m);
	
	int** umas = new int* [n];
	int* tmas = new int[n];

	for (int i = 0; i < n; i++) umas[i] = new int[m];	//	Создание двумерного динамического массива
		
	for (int i = 0; i < n; i++)		//	Заполнение массива
		for (int j = 0; j < m; j++)
		{
			do umas[i][j] = rand();
			while (umas[i][j] > 999);
		}

	printf("Исходный массив:\n");		//	Ввывод исходного массива
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf(" %5d", umas[i][j]);
		}
		printf("\n");
	}

	//	====	====	====	====	====	====	====	====	====	====	====	====

	for (int i = 0; i < n; i++)
	{
		tmas[i] = umas[i][0];
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (tmas[i] > tmas[j]) {
				temp = tmas[i];
				tmas[i] = tmas[j];
				tmas[j] = temp;
				for (int k = 0; k < m; k++) {
					temp = umas[i][k];
					umas[i][k] = umas[j][k];
					umas[j][k] = temp;
				}
			}

	//	====	====	====	====	====	====	====	====	====	====	====	====
	
	printf("\nРезультат:\n");			//	Ввывод результата
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf(" %5d", umas[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) delete[]umas[i];	//	Очистка массива
	delete[]umas;
	umas = NULL;

	_getch();
	return 0;
}