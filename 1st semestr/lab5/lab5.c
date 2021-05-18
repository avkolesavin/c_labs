#include <stdio.h>
#include <stdlib.h>

/*
    Дана строка, содержащая слова, разделенные одним или несколькими разделительными 
    символами (пробелами, табуляторами), в начале строки и в конце строки также могут 
    находиться разделительные символы. Сформировать новую строку, в которой из слов 
    исходной строки удалены все символы, стоящие на четных местах. Слова в новой строке 
    разделяются одним пробелом. В начале строки и в конце строки не должно быть 
    разделительных символов.
*/

int getStringLength(char *str)
{
    if (str != NULL)
    {
        int length = 0;

        while (str[length] != '\0')
            length++;

        return length;
    }

    return 0;
}

int currentIndex = 0;
int stringLength = 0;
char *bufferString = NULL;
char *tokenizeString(char *str, char *delimeters)
{
    int delimetersLength = getStringLength(delimeters);
    if (delimeters == NULL || delimetersLength == 0)
    {
        return str;
    }

    if (str != NULL)
    {
        bufferString = str;
        stringLength = getStringLength(str);
    }
    else
    {
        if (bufferString == NULL || currentIndex >= stringLength)
            return NULL;
    }

    int tokenLength = 0;
    char *token = calloc(0, sizeof(char));
    int isTokenReady = 0;

    for (; currentIndex < stringLength; currentIndex++)
    {
        char currentChar = bufferString[currentIndex];
        int i, isCurrentCharDelimeter = 0;

        for (i = 0; i < delimetersLength; i++)
            if (currentChar == delimeters[i])
                isCurrentCharDelimeter = 1;

        if (!isCurrentCharDelimeter && isTokenReady)
            return token;

        if (isCurrentCharDelimeter && tokenLength > 0)
            isTokenReady = 1;

        if (!isCurrentCharDelimeter)
        {
            tokenLength++;
            realloc(token, tokenLength * sizeof(char));
            token[tokenLength - 1] = currentChar;
        }
    }

    return token;
}

int main()
{
    char str[100];
    char *delimeters = " \t";

    while (1)
    {
        printf("Input string: ");
        gets(str);

        if (getStringLength(str) == 0)
            return 0;

        printf("Entered string '%s'\n", str);

        char *word = tokenizeString(str, delimeters);

        char *resultString = malloc(0);
        int resultStringLength = 0;

        while (word != NULL)
        {
            int wasCharInserted = 0;
            for (int i = 0, wordLength = getStringLength(word); i < wordLength; i++)
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

            word = tokenizeString(NULL, delimeters);
        }
        realloc(resultString, (resultStringLength - 1) * sizeof(char));

        printf("Result string: %s\n", resultString);

        free(resultString);
    }

    return 0;
}