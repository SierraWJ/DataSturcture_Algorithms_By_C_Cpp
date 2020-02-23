#include <stdio.h>
#include <stdlib.h>

typedef struct _Element {
	int key;
	struct _Element *prev;//이전 노드의 주소를 저장
	struct _Element *next;//다음 노드의 주소를 저장
}Element;

typedef struct _Linked_List {
	Element *head;//head 노드의 주소를 저장
	Element *tail;//tail 노드의 주소를 저장
}Linked_List;

void list_print(Linked_List *L);
Element *list_search(Linked_List *L, int k);
void list_insert(Linked_List *L, int k);
void list_delete(Linked_List *L, int k);
int main(void) {
	Linked_List L;
	int x;
	int menu;

	L.head = NULL;
	L.tail = NULL;

	while (1) {
		printf("select menu : 1)insert , 2)delete , default)exit ");
		scanf("%d", &menu);
		if (menu == 0) {
			printf("insert : ");
			scanf("%d", &x);
			list_insert(&L, x);
			list_print(&L);
		}
		else if (menu == 1) {
			printf("delete : ");
			scanf("%d", &x);
			list_delete(&L, x);
			list_print(&L);
		}
		else
			break;
	}
	return 0;
}
void list_print(Linked_List *L){
	Element *x;

	x = L->head;
	while (x!=NULL) {
		printf("%d ", x->key);
		x = x->next;
	}
	printf("\n");
}
Element *list_search(Linked_List *L, int k){
	Element *x;

	x = L->head;
	while (x != NULL && x->key != k)
		x = x->next;
	return x;
}
void list_insert(Linked_List *L, int k) {
	Element *x;

	x = (Element*)malloc(sizeof(Element));
	x->key = k;

	x->next = L->head;
	if (L->head != NULL)
		L->head->prev = x;
	L->head = x;
	x->prev = NULL;
}
void list_delete(Linked_List *L, int k) {
	Element *x;

	x = list_search(L, k);
	if (x != NULL) {
		if (x->prev != NULL)
			x->prev->next = x->next;
		else
			L->head = x->next;
		if (x->next != NULL)
			x->next->prev = x->prev;
		free(x);
	}
}
