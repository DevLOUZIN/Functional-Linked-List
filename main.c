#include <stdio.h> 
#include <stdlib.h>

typedef struct LinkedNode {
    int value;
    struct LinkedNode *next;
}no;

typedef struct {
    no *start;
    int tam;
}list;

void create_List(list *lista) {
    lista->start = NULL;
    lista->tam = 0;
}


void addstart(list *node, int value) {
    no *new = malloc(sizeof(no));
    new->value = value;
    new->next = node->start;
    node->start = new;
    node->tam = node->tam + 1;
}

void addEnd(list *node, int value) {
    no *new = malloc(sizeof(no));
    no *aux = malloc(sizeof(no));
    new->value = value;
    new->next = NULL;
    if(node->start == NULL) {
        addstart(node, value);
    } else {
        aux = node->start;
        while(aux->next) 
            aux = aux->next;
        aux->next = new;
        node->tam++;
    }
}

void addMid(list *node, int value, int ref) {
    no *new = malloc(sizeof(no));
    no *aux = malloc(sizeof(no));
    if(node->start == NULL) {
        addstart(node, value);
    } else {
        aux = node->start;
        while(aux->next && aux->value != ref)
            aux = aux->next;
        new->value = value;
        new->next = aux->next;
        aux->next = new;
    }
}

void addOrd(list *node, int value) {
    int ref = value;
    no *new = malloc(sizeof(no));
    no *aux = malloc(sizeof(no));
    if(node->start == NULL) {
        addstart(node, value);
    } else {
        aux = node->start;
        while(aux->next && aux->value >= ref)
            aux = aux->next;
        new->value = value;
        new->next = aux->next;
        aux->next = new;
    }
}

void printlist(list lista) {
    no *node = lista.start;
    do {
        printf("%d | ", node->value);
        node = node->next;
    } while(node);
}

int main() {
    int opt;
    list lista;
    create_List(&lista);

    int value;
    do {
        printf("\n1 - addstart | 2 - addEnd | 3 - addMid | 4 - addOrd | 5 - printlist: "); 
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                
                printf("Put the value: ");
                scanf("%d", &value);
                addstart(&lista, value);
                break;
            }
            case 2: {
                
                printf("Put the value: ");
                scanf("%d", &value);
                addEnd(&lista, value);
                break;
            }
            case 3: {
                
                int ref;
                printf("Put the value: ");
                scanf("%d", &value);
                printf("Put the reference value: ");
                scanf("%d", &ref);
                addMid(&lista, value, ref);
                break;
            }
            case 4: {
                printf("Put the value: ");
                scanf("%d", &value);
                addOrd(&lista, value);
                break;
            }
            case 5: {
                printlist(lista);
                break;
            }
        }
    } while(opt != 0);

    printf("Hello world");
    system("pause");
    return 0;
}
