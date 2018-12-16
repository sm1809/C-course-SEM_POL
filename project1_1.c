#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Linked list declaration */


typedef struct linked_list_element {
    int val;
    
    struct linked_list_element* next;
    
} lle;


typedef struct linked_list {
    lle* head;
    
    int length;
} ll;

/* Function New - creates new list */

ll*
ll_new() {
    
    ll* list = (ll *) malloc(sizeof(ll));
    
    if (list==NULL) return list;
    
    list -> head = NULL;
    
    list -> length = 0;
    
    return list;
};

/* Function Delete - deletes the list */

int
ll_delete(ll* list) {
    
    if (list == NULL) return 1;
    
    lle* el = list -> head;
    
    while (el != NULL) {
        lle* next = el->next;
        free(el);
        el = next;
    }
    
    return 0;
}

lle*
lle_new(int val) {
    
    lle* new = (lle *) malloc(sizeof(lle));
    if (new == NULL) return NULL;
    
    new->val = val;
    new->next = NULL;
    
    return new;
}

/* Insert function - adds a new element to the beginning of the list */

int
ll_insert(ll* list, int val) {
    
    if (list == NULL) return 1;
    
    lle* new = lle_new(val);
    
    if (list->head == NULL) {
        
        list->head = new;

    }
    else {
        lle* head = list -> head;
        
        new -> next = head;
        
        list -> head = new;
    }
    
    list->length += 1;
    
    return 0;
    
}

/* Function Remove - removes all elements in the list with scanned value */

int
ll_remove(ll* list, int val) {
    
    if (list == NULL) return 1;
    if (list->head == NULL) return 0;
    
    if (list->head->val == val) {
        if (list->head->next == NULL) ll_delete(list);
        else {
            lle* next = list->head->next;
            free(list->head);
            list->head = next;
        }
    }
    lle* tmp = list->head;
    lle* prev = list->head;
    while (tmp != NULL) {
        if (tmp->val == val) {
            lle* next = tmp->next;
            prev->next = tmp->next;
            free(tmp);
            tmp = next;
        }
        else {
            prev = tmp;
            tmp = tmp->next;
        }
    }

    return 0;
}

/* Function Print - prints all values from the list */

int ll_print(ll* list)
{
    if (list == NULL) return 1;
    
    lle* tmp = (lle *) malloc(sizeof(lle));
    if (tmp == NULL) return 1;
    tmp = list->head;
    
    while (tmp != NULL)
    {
        printf(" %d ", tmp->val);
        tmp = tmp->next;
    }
    
    free(tmp);
    
    return 0;
}

// Example

int main(void)
{
    
    ll* a = ll_new();
    ll_insert(a, 1);
    ll_insert(a, 2);
    ll_insert(a, 3);
    
    ll_print(a);
    ll_delete(a);
    
    return 0;
}

