#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Дана строка, содержащая слова, разделенные одним или несколькими разделительными 
    символами (пробелами, табуляторами), в начале строки и в конце строки также могут 
    находиться разделительные символы. Сформировать новую строку, в которой из слов 
    исходной строки удалены все символы, стоящие на четных местах. Слова в новой строке 
    разделяются одним пробелом. В начале строки и в конце строки не должно быть 
    разделительных символов.
*/

int main()
{
    char *str;
    char *delimeters = " \t";

    while (1)
    {
        printf("Input string: ");
        gets(str);

        if (strlen(str) == 0)
        {
            return 0;
        }

        printf("Entered string '%s'\n", str);

        char *word = strtok(str, delimeters);

        char *resultString = calloc(0, sizeof(char));
        int resultStringLength = 0;

        while (word != NULL)
        {
            int wasCharInserted = 0;
            for (int i = 0, wordLength = strlen(word); i < wordLength; i++)
            {
                if (i % 2 != 0)
                {
                    resultStringLength++;

                    realloc(resultString, resultStringLength * sizeof(char));
                    resultString[resultStringLength - 1] = word[i];

                    wasCharInserted = 1;
                }
            }

            if (wasCharInserted)
            {
                resultStringLength++;
                realloc(resultString, resultStringLength * sizeof(char));
                resultString[resultStringLength - 1] = ' ';
            }

            word = strtok(NULL, delimeters);
        }
        realloc(resultString, (resultStringLength - 1) * sizeof(char));

        printf("Result string: %s\n", resultString);

        free(resultString);
    }

    return 0;
}