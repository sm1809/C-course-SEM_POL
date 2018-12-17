#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Linked list declaration */

typedef struct list list;
typedef struct item {
    char* name;
    int num;
} item;
struct list {
    list* next;
    item item;
};

/* Function Find - finds number for the name that was given */

int find(list* head, char * name) {
    list* list;
    if (!head)
        return 0;
    for (list = head; list; list = list->next)
        if (!strcmp(list->item.name, name)) {
            printf("%d\n", list->item.num);
            return 1;
        }
    // if no number for the name
    printf("NO\n");
    return 0;
}

/* Function insert - inserts a new record into the list (Then OK) or
   changes the record with the name given (Then Changed..) */

list* insert(list* head, item item) {
    list* list1;
    list* new_item = malloc(sizeof(list));
    int flag = 0;
    // If there was no elements
    if (head == NULL)
    {
        head = (list*)malloc(sizeof(list));
        head->item.name = item.name;
        head->item.num = item.num;
        head->next = NULL;
        printf("OK\n");
        return head;
    }
    // If there was element
    for (list1 = head; list1; list1 = list1->next)
        if (!strcmp(list1->item.name, item.name)) {
            printf("Changed. Old value = %d\n", list1->item.num);
            list1->item.num = item.num;
            free(new_item);
            flag = 1;
            }
    if (flag != 1) printf("OK\n");
    new_item->item.name = item.name;
    new_item->item.num = item.num;
    if (head)
        new_item->next = head;
    head = new_item;
    return head;
}

/* Example */

int main(void)
{
    char c1[3];
    c1[0] = 'P';
    c1[1] = 'e';
    c1[2] = 0;
    char c2[3];
    c2[0] = 'S';
    c2[1] = 'r';
    c2[2] = 0;
    list* b = NULL;
    item c;
    c.num = 2017;
    c.name = c1;
    b = insert(b, c);
    c.num = 2018;
    c.name = c2;
    b = insert(b, c);
    find(b, c1);
    find(b, c2);
    c.name = c1;
    b = insert(b,c);
    
    return 0;
}
