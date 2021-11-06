// Lab2_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	float x, y, b, s;
	int f = 0;

	printf("Vvedite x = ");
	scanf_s("%f", &x);
	printf("Vvedite y = ");
	scanf_s("%f", &y);
	printf("Vvedite b = ");
	scanf_s("%f", &b);
	printf("Vvedite f =\n 1) sh(x)  2) x^2  3) exp(x)\nVvedite f = ");
	scanf_s("%d", &f);

	switch (f)
	{
	case 1:
		f = sinh(x);
		break;
	case 2:
		f = x * x;
		break;
	case 3:
		f = exp(x);
		break;
	default:
		printf("Error");
		return 0;
		break;
	}

	if (x * b > 1 && x * b < 10) {
		s = exp(f);
	}
	else if (x * b > 12 && x * b < 40) {
		s = pow(fabs(f + 4*y), 1.0 / 3.0);
	}
	else {
		s = y * f * f;
	}

	printf("s = %f", s);

	_getch();
	return 0;
}