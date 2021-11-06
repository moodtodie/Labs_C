// Lab8_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

typedef double (*uf)(double, double, int&);
void output(double, double, double, double, uf);
double funY(double, double, int&);
double funS(double, double, int&);

int main()
{
	double a = -0.5, b = 0.5, h = 0.1, eps = 0.1;

	printf("    x   |     Y(x)    |  k  \n");
	output(a, b, h, eps, funY);
	printf("\n    x   |     S(x)    |  k  \n");
	output(a, b, h, eps, funS);
}

void output(double a, double b, double h, double eps, uf fun) {
	int k = 0;
	double result;
	for (double x = a; x < b + h / 2; x += h)
	{
		result = fun(x, eps, k);
		printf("%7.2lf | %10lf  |  %-5d     \n", x, result, k);
	}
}

double funY(double x, double eps, int &k) {
	double result = 0.25 * log((1 + x) / (1 - x)) - 0.5 * atan(x);
	return result;
}

double funS(double x, double eps, int &k) {
	double result, a, c;
	result = a = c = x;

	for (k = 1; fabs(c) > eps ; k++)
	{
		int t = 4 * k - 1;
		c = pow(x,t) / t;
		a *= -c;
		result += a;
	}

	return result;
}