// Lab6_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "rus");

	const int n = 50;
	char str[n];

	printf(" Введите строку состоящию из произвольных символов:\n");
	fgets(str, n, stdin);			//	Заполнение массива

	printf(" Число из строки:\n");

	for (int i = 0; i < n ; i++)	//	Фильтрация
		if (isdigit(str[i]))
			printf(" %c", str[i]);//	Вывод массива

	_getch();
	return 0;
}