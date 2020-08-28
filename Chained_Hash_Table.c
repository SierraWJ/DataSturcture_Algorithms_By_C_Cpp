#include <stdio.h>
#include <stdlib.h>
#define NIL -1
#define M 10


typedef struct _node{
    int value;
    struct _node *prev;
    struct _node *next;
}node;
typedef struct _linkedlist{
    node *head;
    node *tail;
}linkedlist;

int HashFunction(int k, int m);
void Chained_Hash_Insert(linkedlist *L, int x);
node *Chained_Hash_Search(linkedlist *L, int k);
void Chained_Hash_Delete(linkedlist *L, int x);
void Chained_Hash_Print(linkedlist *L);

int main(){
    linkedlist T[M] = { NULL, };
    int i,s, x, value;
    int exit;
    printf("Hash Table Simulator\n");
    while (1){
        printf("Menu\n");
        printf("1. Insert , 2. Delete , default. exit :");
        scanf("%d", &s);
        switch (s){
        case 1:
            printf("x : ");
            scanf("%d", &x);
            Chained_Hash_Insert(&T[HashFunction(x, M)], x);
            break;
        case 2:
            printf("x : ");
            scanf("%d", &x);
            Chained_Hash_Delete(&T[HashFunction(x, M)], x);
            break;
        default:
            exit = 0;
            break;
        }
        if (exit == 0) break;
        for (i = 0; i < 10; i++) Chained_Hash_Print(&T[i]);

    }

}

int HashFunction(int k, int m){
    return k % m;
}
void Chained_Hash_Insert(linkedlist *L, int x){
    node *tmp;
    tmp = (node*)malloc(sizeof(node));
    tmp->value = x;
    tmp->next = L->head;
    if (L->head != NULL)
        L->head->prev = tmp;
    L->head = tmp;
    tmp->prev = NULL;
}
node *Chained_Hash_Search(linkedlist *L, int k){
    node *x;

    x = L->head;
    while (x != NULL && x->value != k) x = x->next;
    return x;
}
void Chained_Hash_Delete(linkedlist *L, int x){
    node *tmp;

    tmp = Chained_Hash_Search(L, x);
    if (tmp != NULL){
        if (tmp->prev != NULL) tmp->prev->next = tmp->next;
        else L->head = tmp->next;
        if (tmp->next != NULL) tmp->next->prev = tmp->prev;
        free(tmp);
    }

}
void Chained_Hash_Print(linkedlist *L){
    node *x;
    x = L->head;
    while (x != NULL){
        printf("%d ", x->value);
        x = x->next;
    }
    printf("\n");
}
