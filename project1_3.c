#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Linked list declaration */


typedef struct linked_list_element {
    int val;
    
    struct linked_list_element* next;
    struct linked_list_element* previous;
    
} lle;


typedef struct linked_list {
    lle* head;
    lle* tail;
    
    int length;
} ll;



ll*
ll_new() {
    
    ll* list = (ll *) malloc(sizeof(ll));
    
    if (list==NULL) return list;
    
    list -> head = NULL;
    list -> tail = NULL;
    
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
lle_new(int val, lle* previous) {
    
    lle* new = (lle *) malloc(sizeof(lle));
    if (new == NULL) return NULL;
    
    new->val = val;
    new->next = NULL;
    new->previous = previous;
    
    return new;
}

/* Function Push - adds new element to the end */

int
ll_push(ll* list, int val) {
    
    if (list == NULL) return 1;
    
    if (list->head == NULL) {
        lle* new = lle_new(val, NULL);
        list->head = new;
        list->tail = new;
    }
    else {
        lle* tail = list -> tail;
        tail -> next = lle_new(val, tail);
        list -> tail = tail -> next;
    }
    
    list->length += 1;
    
    return 0;
}

/* Function Shift - inserts first element to the certain position (index) */

int
ll_shift(ll* list, int index) {
    
    if (list->length <= index) return -1;
    
    lle* target_element=list->head;
    
    for (int i = 0; i < index; ++i) {
        target_element = target_element->next;
    }
    
    return target_element->val;
}

/* Function Pop - inserts last element to the certain position (index) */

int
ll_pop(ll* list, int index) {
    
    if (list->length <= index) return -1;
    
    lle* target_element=list->tail;
    
    for (int i = 0; i < index; ++i){
        target_element = target_element->previous;
    }
    
    return target_element->val;
}

/* Unshift function - adds a new element to the beginning of the list */

int
ll_unshift(ll* list, int val) {
    
    if (list == NULL) return 1;
    
    lle* new = lle_new(val, NULL);
    
    if (list->head == NULL) {
    
        list->head = new;
        list->tail = new;
    }
    else {
        lle* head = list -> head;
        
        head -> previous = new;
        new -> next = head;
        
        list -> head = new;
    }
    
    list->length += 1;
    
    return 0;
    
}

/* Reverse function - going through the list and changing next and previous with each other */

int ll_reverse(ll* list) {
    
    if (list == NULL) return 1;
    if (list->head == NULL) return 0;
    
    lle* tmp = (lle *) malloc(sizeof(lle));
    if (tmp == NULL) return 1;
    ll* move = (ll*) malloc(sizeof(ll));
    if (move == NULL) return 1;
    
    tmp->next = list->head->next;
    tmp->previous = list->head;
    move->head = list->head->next;
    move->tail = list->head;
    list->tail = move->tail;
    
    list->head->next = list->head->previous;
    list->head->previous = tmp->next;

    
    while (move->head->next != NULL) {
        
        tmp->next = move->head->next;
        tmp->previous = move->head->previous;
        
        move->head->previous = tmp->next;
        move->head->next = tmp->previous;
        
        move->head->previous = move->head;
        move->head = tmp->next;
        
    }
    tmp->previous = move->head->previous;
    list->head = move->head;
    list->head->previous = move->head->next;
    list->head->next = tmp->previous;
    
    free(tmp);
    free(move);
    
    return 0;
}

/* Example */
int main(void)
{
    
    ll* a = ll_new();
    ll_push(a, 1);
    ll_push(a, 2);
    ll_push(a, 3);
    
    printf("%d\n", a->head->val);
    ll_reverse(a);
    printf("%d\n", a->head->val);
    ll_delete(a);
    return 0;
}
