#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils.h"

/*
Вариант 27
Из входного потока вводится непрямоугольная матрица целых чисел [aij], i = 1, …, m, j = 1, …, ni.
Значения m и ni заранее не известны и вводятся из входного потока.
Сформировать новую матрицу, поместив в ее i-ую строку те элементы из i-ой строки исходной матрицы,
в записи которых цифры расположены по возрастанию.

Исходную и полученную матрицы вывести в выходной поток с необходимыми комментариями.
*/

int isDigitsAscending(int n)
{
    int number = n < 0 ? n * -1 : n;
    int digitBefore = INT32_MAX;

    while (number != 0)
    {
        int currentDigit = number % 10;
        number /= 10;

        if (digitBefore < currentDigit)
            return 0;
        else
            digitBefore = currentDigit;
    }

    return 1;
}

int sizeOfArray(int *array)
{
    int c = 0;

    while (array[c] != '\0')
        c++;

    return c;
}

void printMatrix(int **matrix, int rowsCount)
{
    printf("[\n");
    for (int i = 0; i < rowsCount; i++)
    {
        int rowLength = sizeOfArray(matrix[i]);

        printf("  [");
        for (int j = 0; j < rowLength; j++)
        {
            if (j == (rowLength - 1))
                printf("%d", matrix[i][j]);
            else
                printf("%d, ", matrix[i][j]);
        }

        if (i != (rowsCount - 1))
            printf("],\n");
        else
            printf("]\n");
    }
    printf("]\n");
}

int main()
{
    int m = 0;

    printf("Введите количество строк матрицы: ");
    scanf("%d", &m);

    int **originMatrix = calloc(m, sizeof(int *));
    int **resultMatrix = calloc(m, sizeof(int *));

    for (int i = 0; i < m; i++)
    {
        int ni = 0;
        printf("\nКоличество элементов для %d-й строки: \n", i + 1);
        scanf("%d", &ni);

        int *row = calloc(ni, sizeof(int));

        for (int j = 0; j < ni; j++)
        {
            printf("Значение для %d-го элемента %d-й строки: ", j + 1, i + 1);
            scanf("%d", &row[j]);
        }

        originMatrix[i] = row;
    }

    printLn("\nИсходная матрица: ");
    printMatrix(originMatrix, m);

    for (int i = 0; i < m; i++)
    {
        int rowElements = 0;
        int *row = calloc(0, sizeof(int));

        for (int j = 0, ni = sizeOfArray(originMatrix[i]); j < ni; j++)
        {
            if (isDigitsAscending(originMatrix[i][j]))
            {
                row = realloc(row, (++rowElements * sizeof(int)));
                row[rowElements - 1] = originMatrix[i][j];
            }
        }

        resultMatrix[i] = row;
    }

    printLn("Результирующая матрица: ");
    printMatrix(resultMatrix, m);

    for (int i = 0; i < m; i++)
    {
        free(originMatrix[i]);
        free(resultMatrix[i]);
    }

    free(originMatrix);
    free(resultMatrix);

    return 0;
}
