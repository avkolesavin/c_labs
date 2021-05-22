#include <stdlib.h>

#include "list.h"
#include "../utils.h"

struct StringsList *createStringsList()
{
    struct StringsList *list = malloc(sizeof(struct StringsList));
    list->length = 0;
    list->head = NULL;

    return list;
}

struct CharsList *createCharsList()
{
    struct CharsList *list = malloc(sizeof(struct CharsList));
    list->length = 0;
    list->head = NULL;

    return list;
}

void appendItemToCharsList(struct CharsList *list, char value)
{
    struct CharsListItem *newItem = malloc(sizeof(struct CharsListItem));
    newItem->value = value;
    newItem->next = NULL;

    if (list->head == NULL)
    {
        list->head = newItem;
        list->length = 1;
        return;
    }

    struct CharsListItem *tail = list->head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = newItem;
    list->length++;
}

void appendItemToStringsList(struct StringsList *list, struct CharsList *value)
{
    struct StringsListItem *newItem = malloc(sizeof(struct StringsListItem));
    newItem->value = value;
    newItem->next = NULL;

    if (list->head == NULL)
    {
        list->head = newItem;
        list->length = 1;

        return;
    }

    struct StringsListItem *tail = list->head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = newItem;
    list->length++;
}

void printCharsList(struct CharsList *list)
{
    char *string = calloc(list->length, sizeof(char));

    for (
        struct CharsListItem *item = list->head;
        item != NULL;
        item = item->next)
    {
        *string = item->value;
        string++;
    }

    string -= list->length;

    printString(string);

    free(string);
}

void printStringsList(struct StringsList *list)
{
    for (
        struct StringsListItem *item = list->head;
        item != NULL;
        item = item->next)
    {
        printCharsList(item->value);
    }
}

void freeCharsList(struct CharsList *list)
{
    if (list != NULL)
    {
        if (list->length > 0)
        {
            for (struct CharsListItem *item = list->head; item != NULL;)
            {
                struct CharsListItem *itemToFree = item;
                item = item->next;

                free(itemToFree);
            }
        }

        free(list);
    }
}

void freeStringsList(struct StringsList *list)
{
    if (list != NULL)
    {
        if (list->length > 0)
        {
            for (struct StringsListItem *item = list->head; item != NULL;)
            {
                struct StringsListItem *itemToFree = item;
                item = item->next;

                if (itemToFree->value != NULL)
                {
                    freeCharsList(itemToFree->value);
                }

                free(itemToFree);
            }
        }

        free(list);
    }
}
