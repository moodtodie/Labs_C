
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
	double x, y, a, s, h, k, n = 3, b = 1;
	s = y = 0;
	x = a = 0.1;
	h = (b - a) / 10;

	do {
		for (int i = 1; i <= n; i++)
		{
			s += pow(-1, i + 1.0) * pow(x, (2 * i + 1)) / ((4 * i * i) - 1);
		}

		y += ((1 + x * x) / 2 * atan(x) - x / 2);

		printf(" x = %-6.3lf", x);
		printf("   Y(x) = %-9.6lf", y);
		printf("   S(x) = %-9.6lf", s);
		printf("   |Y(x) - S(x)| = %-.4lf", abs(y-s));
		printf("\n");

		x += h;
	} while (x <= b + h / 2);

	_getch();
	return 0;
}