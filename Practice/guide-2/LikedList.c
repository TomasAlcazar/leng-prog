#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
} ;

void append(struct Node **head, int value) {
    struct Node *n = malloc(sizeof *n);
    if (!n) return;
    n->value = value; n->next = NULL;
    if (!*head) {*head = n; return;}
    struct Node *current = *head;
    while (current->next) current = current->next;
    current->next = n;
}

void prepend(struct Node **head, int value) {
    struct Node *n = malloc(sizeof *n);
    if (!n) return;
    n->value = value; n->next = *head;
    *head = n;
}

int delete(struct Node **head, int value) {
    if (!*head) return 0;
    struct Node *current = *head;
    if (current->value == value) {
        *head = current->next;
        free(current);
        return 1;
    }
    while (current->next && current->next->value != value) current = current->next;
    if (!current->next) return 0;
    struct Node *to_delete = current->next;
    current->next = to_delete->next;
    free(to_delete);
    return 1;
}

int find(struct Node *head, int value) {
    struct Node *current = head;
    while (current) {
        if (current->value == value) return 1;
        current = current->next;
    }
    return 0;
}

void print(struct Node *head) {
    struct Node *current = head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void free(struct Node **head) {
    struct Node *current = *head;
    while (current) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int len(struct Node *head) {
    int len = 0;
    struct Node *current = head;
    while (current) {
        len++;
        current = current->next;
    }
    return len;
}
