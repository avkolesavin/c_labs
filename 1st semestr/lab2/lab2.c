#include <stdio.h>
#include <math.h>

double my_sin(double x, int n)
{
    double sum = 0;
    double fact = 1;
    double exp = x;

    for (int i = 0; i <= n; i++)
    {
        fact *= i == 0 ? 1.0 : (2 * i) * (2 * i + 1);
        exp *= i == 0 ? 1 : x * x;

        sum += (exp / fact) * (i % 2 == 0 ? 1 : -1);
    }

    return sum;
}

void get_x(double *x)
{
    do
    {
        printf("Введите значени для x : ");
        scanf("%lf", x);
    } while (*x <= 1.0);
}

void get_n(int *n)
{
    do
    {
        printf("Введите значени для n (n >= 0): ");
        scanf("%d", n);
    } while (*n < 0);
}

int main()
{
    double x;
    int n;
    char willContinue = 'y';

    printf("Программа считает значение функции sin(x)\n");
    printf("используя разложение в ряд Маклорена до n-го элемента\n\n");
    do
    {
        get_x(&x);
        get_n(&n);

        printf("\nx = %f\nn = %d\n\n", x, n);

        printf("my_sin(%lf) = %lf\n", x, my_sin(x, n));
        printf("sin(%lf) = %lf\n", x, sin(x));

        printf("\nНачать заново? (y/n): ");
        scanf("\r%c", &willContinue);
    } while (willContinue != 'n');

    printf("\nПока пока :3\n");

    return 0;
}