#include <stdio.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

void add(struct list **No, int value) {
    struct list *new = malloc(sizeof(struct list));
    new->value = value;
    new->next = *No;
    *No = new;
}

void show(struct list *No) {
    do {
        printf("%d | ", No->value);
        No = No->next;
    } while(No != NULL);
}

void addEnd(struct list **No, int value) {
    struct list *new = malloc(sizeof(struct list));
    struct list *aux = malloc(sizeof(struct list));
    new->value = value;
    new->next = NULL;
    if(*No == NULL) {
        *No = new;
    } else {
        aux = *No;
        while (aux->next)
            aux = aux->next;
        aux->next = new;
    }
}

int main() {
    struct list *node = NULL;
    int opt;
    do {
        printf("\n1 - Add list \t 2 - Add in start \t 3 - Remove list \t 4 - Show List: ");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1: {
                int value;
                printf("Add a value: ");
                scanf("%d", &value);
                addEnd(&node, value);
                break;
            }
            case 2: {
                int value;
                printf("Add a value: ");
                scanf("%d", &value);
                add(&node, value);
                break;
            }
            case 3: {
                removeList(node);
            }
            case 4: {
                show(node);
                break;
            }
        } 
    } while(opt != 0);
    system("pause");
    return 0;
} 