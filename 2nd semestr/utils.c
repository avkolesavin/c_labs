#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printChar(char c)
{
    printf("\033[00;32m'%c'\n\033[00;0m", c);
}

void printString(char *str)
{
    printf("\033[00;32m\"%s\"\n\033[00;0m", str);
}

void printInt(int n)
{
    printf("\033[00;1m%d\n\033[00;0m", n);
}

void printLn(char *str)
{
    printf("%s\n", str);
}

int stringConcat(char *distString, char *string)
{
    int newLength = strlen(distString) + strlen(string);

    distString = realloc(distString, (newLength + 1) * sizeof(char));
    strcat(distString, string);

    return newLength;
}

char *readLine()
{
    const unsigned short BUFFER_SIZE = 5;

    char *buffer = calloc(BUFFER_SIZE, sizeof(char)),
         *resultString = calloc(0, sizeof(char));
    int resultStringLength = 0,
        bufferIndex = 0;

    char c;
    while (1)
    {
        c = fgetc(stdin);

        if (c == '\n')
        {
            stringConcat(resultString, buffer);
            break;
        }
        else
        {
            buffer[bufferIndex] = c;
            bufferIndex++;

            if (bufferIndex == BUFFER_SIZE)
            {
                bufferIndex = 0;
                resultStringLength = stringConcat(resultString, buffer);

                free(buffer);
                buffer = NULL;
                buffer = calloc(BUFFER_SIZE, sizeof(char));
            }
        }
    }

    free(buffer);

    return resultString;
}