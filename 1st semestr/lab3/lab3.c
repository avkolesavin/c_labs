#include <stdio.h>
#include <stdlib.h>

/* 
Дана последовательность из n целых элементов. Удалить из нее все вхождения минимального элемента,
затем отсортировать ее по убыванию. Вывести на экран исходную последовательность до удаления,
после удаления и после сортировки.
*/

enum SortDirection
{
    ASC,
    DESC
};

void printArray(int *array, int arraySize)
{
    printf("[ ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d", array[i]);
        if (i != arraySize - 1)
        {
            printf(", ");
        }
    }
    printf(" ]");
}

void printArrayWithMessage(char *message, int *array, int arraySize)
{
    printf("%s", message);
    printArray(array, arraySize);
    printf("\n");
}

int *copyArray(int *originalArray, int arraySize)
{
    int *coppiedArray = malloc(arraySize * sizeof(int));

    int i;
    for (i = 0; i < arraySize; i++)
    {
        coppiedArray[i] = originalArray[i];
    }

    return coppiedArray;
}

int *selectionSort(int *array, int arraySize, enum SortDirection sortDirection)
{
    int *sortedArray = copyArray(array, arraySize);

    int i;
    for (i = 0; i < arraySize; i++)
    {
        int selectedIndex = i;

        int j;
        for (j = i; j < arraySize; j++)
        {
            if (sortDirection == ASC && sortedArray[selectedIndex] > sortedArray[j])
            {
                selectedIndex = j;
                continue;
            }
            if (sortDirection == DESC && sortedArray[selectedIndex] < sortedArray[j])
            {
                selectedIndex = j;
                continue;
            }
        }

        int tmp = sortedArray[i];
        sortedArray[i] = sortedArray[selectedIndex];
        sortedArray[selectedIndex] = tmp;
    }

    return sortedArray;
}

int *removeMinimumElements(int *originalArray, int arraySize, int *newElementsCount)
{
    int minimumValue = originalArray[0];

    int i;
    for (i = 0; i < arraySize; i++)
    {
        if (originalArray[i] < minimumValue)
        {
            minimumValue = originalArray[i];
        }
    }

    int minimumElementsCount = 0;
    for (i = 0; i < arraySize; i++)
    {

        if (originalArray[i] == minimumValue)
        {
            minimumElementsCount++;
        }
    }

    int trimmedArraySize = arraySize - minimumElementsCount;
    int *trimmedArray = malloc(trimmedArraySize * sizeof(int));
    int insertIndex = 0;
    for (i = 0; i < arraySize; i++)
    {
        if (originalArray[i] != minimumValue)
        {
            trimmedArray[insertIndex] = originalArray[i];
            insertIndex++;
        }
    }

    *newElementsCount = trimmedArraySize;

    return trimmedArray;
}

int main()
{
    char willContinue = 'y';

    do
    {
        int n;
        printf("Введите количество элементов массива: ");
        scanf("%d", &n);

        int *numbers = malloc(n * sizeof(int));
        printf("Введите зачения для %d элементов последовательности: ", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &numbers[i]);
        }

        printArrayWithMessage("Исходная последовательность: ", numbers, n);

        int trimmedArraySize;
        int *trimmedArray = removeMinimumElements(numbers, n, &trimmedArraySize);
        printArrayWithMessage("После удаления минимальных элементов: ", trimmedArray, trimmedArraySize);

        int *sortedArray = selectionSort(trimmedArray, trimmedArraySize, ASC);
        printArrayWithMessage("После сортировки: ", sortedArray, trimmedArraySize);

        free(trimmedArray);
        free(sortedArray);
        free(numbers);

        printf("Повторить? (y/n): ");
        scanf("\r%c", &willContinue);
    } while (willContinue == 'y');

    return 0;
}