// Lab4_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <stdio.h>
#include <conio.h>
#include <math.h>

#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, k;

    printf("Введите из скольки чисел будет состоять массив k = ");
    scanf_s("%d", &k);

    int *m = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++)
    {
        printf("Введите эллемент массива №%d ", (i + 1));
        scanf_s("%d", &m[i]);
    }

    printf("Ваш массив:\n");                    //  Ввывод массива
    for (int i = 0; i < k; i++) {
        printf(" %d", m[i]);
    }
    printf("\n");

    printf("Введите на сколько сдвинуть эл-ты массива n = ");
    scanf_s("%d", &n);

    n %= k;

    for (int i = 0; i < n; i++)             // n - кол-во сдвигов
    {
        int a = m[k - 1];
        for (int j = (k - 1); j > 0; j--)   //  Единичный сдвиг в право
        {
            m[j] = m[j - 1];
        }
        m[0] = a;
    }

    printf("Ваш массив со сдвигом:\n");         //  Ввывод массива
    for (int i = 0; i < k; i++) {
        printf(" %d", m[i]);
    }
    _getch();
    return 0;
}