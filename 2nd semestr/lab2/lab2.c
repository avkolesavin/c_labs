#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "../utils.h"

int main()
{
    char c;
    struct CharsList *string = createCharsList();
    struct StringsList *originStrings = createStringsList();
    struct StringsList *resultStrings = createStringsList();

    do
    {
        c = getc(stdin);

        if (c != '\n')
            appendItem(string, c);
        else
        {
            appendItem(originStrings, string);
            string = createCharsList();
        }
    } while (c != EOF);

    printf("%s:\n", "Исходный список строк");
    printList(originStrings);

    for (
        struct StringsListItem *originStringsItem = originStrings->head;
        originStringsItem != NULL;
        originStringsItem = originStringsItem->next)
    {
        struct CharsList *resultString = createCharsList();
        char isEllipsis = 0;

        for (
            struct CharsListItem *stringItem = originStringsItem->value->head;
            stringItem != NULL;
            stringItem = stringItem->next)
        {
            if (stringItem->value == '.')
            {
                if (
                    stringItem->next != NULL &&
                    stringItem->next->value == '.' &&
                    !isEllipsis)
                {
                    appendItem(resultString, '.');
                    isEllipsis = 1;
                }

                if (!isEllipsis)
                    appendItem(resultString, ';');
            }
            else
            {
                appendItem(resultString, stringItem->value);
                isEllipsis = 0;
            }
        }

        appendItem(resultStrings, resultString);
    }

    printf("%s:\n", "Итоговый список список строк");
    printList(resultStrings);

    destroyList(string);
    destroyList(originStrings);
    destroyList(resultStrings);

    return 0;
}
