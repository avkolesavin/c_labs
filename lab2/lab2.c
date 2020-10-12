#include <stdio.h>
#include <math.h>

double my_acosh(double x, int n)
{
    double result = log(2 * x);
    double sum = 0;

    double n_fact = 1;
    double n2_fact = 1;

    for (int i = 1; i <= n; i++)
    {
        n2_fact *= (2 * i - 1) * (2 * i);
        n_fact *= i;

        sum += (n2_fact / ((2 << (2 * i - 1)) * n_fact * n_fact)) * ((pow(x, -2 * i)) / (2 * i));
    }

    return result - sum;
}

void get_x(double *x)
{
    do
    {
        printf("Введите значени для x (x > 1.0): ");
        scanf("%lf", x);
    } while (*x <= 1.0);
}
void get_n(int *n)
{
    do
    {
        printf("Введите значени для n (n >= 1): ");
        scanf("%d", n);
    } while (*n < 1);
}

int main()
{
    double x;
    int n;
    char willContinue = 'y';

    printf("Программа считает значение функции acosh(x)\n");
    printf("используя разложение в ряд Маклорена до n элемента\n\n");
    do
    {
        get_x(&x);
        get_n(&n);

        printf("\nx = %f\nn = %d\n\n", x, n);

        printf("my_acosh(%lf) = %lf\n", x, my_acosh(x, n));
        printf("acosh(%lf) = %lf\n", x, acosh(x));

        printf("\nНачать заново? (y/n): ");
        scanf("\r%c", &willContinue);
    } while (willContinue != 'n');

    printf("\nПока пока :3\n");

    return 0;
}