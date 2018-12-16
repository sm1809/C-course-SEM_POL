#include <stdio.h>
#include <stdlib.h>

struct Node {
    char c;
    struct Node* next_;
    struct Node* prev_;
};

struct Stack {
    struct Node* end_;
};

void Stack_push(struct Stack* s, char c) {
    struct Node* vertex = (struct Node*) malloc(sizeof(struct Node));
    vertex->next_ = NULL;
    vertex->prev_ = s->end_;
    vertex->c = c;
    s->end_ = vertex;
    if (vertex->prev_) {
        vertex->prev_->next_ = vertex;
    }
}

void Stack_pop(struct Stack* s) {
    if (!s->end_->prev_) {
        free(s->end_);
        s->end_ = NULL;
    } else {
        s->end_ = s->end_->prev_;
        free(s->end_->next_);
        s->end_->next_ = NULL;
    }
}

int Stack_empty(struct Stack* s) {
    return !s->end_;
}

char Stack_top(struct Stack* s) {
    return s->end_->c;
}

int main() {
    struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack));
    s->end_ = NULL;
    int is_good = 1;
    char c;
    scanf("%c", &c);
    while (c != '\n') {
        if (c == '(' || c == '{') {
            Stack_push(s, c);
        } else if (c == ')') {
            if (Stack_empty(s) || Stack_top(s) != '(') {
                is_good = 0;
                break;
            } else {
                Stack_pop(s);
            }
        } else if (Stack_empty(s) || Stack_top(s) != '{') {
            is_good = 0;
            break;
        } else {
            Stack_pop(s);
        }
        scanf("%c", &c);
    }
    if (is_good && Stack_empty(s)) {
        printf("Yes!\n");
    } else {
        printf("No!\n");
    }
    return 0;
}
