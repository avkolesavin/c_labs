struct CharsListItem
{
    char value;
    struct CharsListItem *next;
};

struct CharsList
{
    int length;
    struct CharsListItem *head;
};

struct StringsListItem
{
    struct CharsList *value;
    struct StringsListItem *next;
};

struct StringsList
{
    int length;
    struct StringsListItem *head;
};

struct StringsList *createStringsList();
struct CharsList *createCharsList();

void appendItemToCharsList(struct CharsList *list, char value);
void appendItemToStringsList(struct StringsList *list, struct CharsList *value);

void printCharsList(struct CharsList *list);
void printStringsList(struct StringsList *list);

void freeStringsList(struct StringsList *list);
void freeCharsList(struct CharsList *list);

#define appendItem(list, value) _Generic((list), struct StringsList *                  \
                                         : appendItemToStringsList, struct CharsList * \
                                         : appendItemToCharsList, default              \
                                         : NULL)(list, value)

#define printList(list) _Generic((list), struct StringsList *           \
                                 : printStringsList, struct CharsList * \
                                 : printCharsList, default              \
                                 : NULL)(list)

#define destroyList(list) _Generic((list), struct StringsList *          \
                                   : freeStringsList, struct CharsList * \
                                   : freeCharsList, default              \
                                   : NULL)(list)