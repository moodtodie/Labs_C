// Lab1_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	float x, y, z, s;
	x = 0.1722;
	y = 6.33;
	z = 3.25e-4;

	s = 5 * atan(x) - 0.25 * acos(x) * (x + 3 * fabs(x - y) + x * x) / (fabs(x - y) * z + x * x);

	printf("s = %.3f", s);

	_getch();
	return 0;
}