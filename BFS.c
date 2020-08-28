#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

#define WHITE	0
#define GRAY	1
#define BLACK	2

#define INF		-1

typedef struct _Vortex {
	int color;
	int d;
	int parent;
}Vortex;

typedef struct _Element {
	int index;
	struct _Element *next;
}Element;

typedef struct _Graph {
	Vortex *V[SIZE];
	Element *adj[SIZE];
}Graph;

typedef struct _Queue {
	Element *head;
	Element *tail;
}Queue;

void print_path(Graph *G, int s, int v);
void breadth_first_search(Graph *G, int s);
void print_graph(Graph *G);
void init_graph(Graph *G, int c[SIZE][SIZE]);
void connect_vortex(Graph *G, int u, int v);
void disconnect_vortex(Graph *G, int u, int v);
void print_queue(Queue *Q);
void push_queue(Queue *Q, int i);
int pop_queue(Queue *Q);
int main(void) {
	Graph G = { 0 };
	int c[SIZE][SIZE] = {
		{ 0, 1, 0, 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 1, 0 },
		{ 0, 0, 1, 0, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 1, 0 },
		{ 0, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 1, 0 }
	};
	init_graph(&G, c);
	breadth_first_search(&G, 1);
	printf("Path : ");
	print_path(&G, 1, 3);
	printf("\n");
	return 0;
}
void print_path(Graph *G, int s, int v) {
	if (v == s) printf("%d ", s);
	else if (G->V[v]->parent == -1) printf("no path\n");
	else{
		print_path(G, s, G->V[v]->parent);
		printf("%d ", v);
	}
}
void breadth_first_search(Graph *G, int s) {
	Queue Q = { 0 };
	Element *tmp;
	int u, v;

	for (u = 0; u < SIZE; u++) {
		if (u != s) {
			G->V[u]->color = WHITE;
			G->V[u]->d = INF;
			G->V[u]->parent = -1;
		}
	}
	G->V[s]->color = GRAY;
	G->V[s]->d = 0;
	G->V[s]->parent = -1;
	push_queue(&Q, s);

	print_graph(G);
	print_queue(&Q);
	printf("\n");
	while (Q.head != NULL) {
		u = pop_queue(&Q);
		for (tmp = G->adj[u]; tmp != NULL; tmp = tmp->next) {
			v = tmp->index;
			if (G->V[v]->color == WHITE) {
				G->V[v]->color = GRAY;
				G->V[v]->d = G->V[u]->d + 1;
				G->V[v]->parent = u;
				push_queue(&Q, v);
			}
		}
		G->V[u]->color = BLACK;
		print_graph(G);
		print_queue(&Q);
		printf("\n");
	}
}
void print_graph(Graph *G) {
	int i;

	printf("Color : ");
	for (i = 0; i < SIZE; i++) printf("%d ", G->V[i]->color);
	printf("\n");
	printf("d : ");
	for (i = 0; i < SIZE; i++) printf("%d ", G->V[i]->d);
	printf("\n");
}
void init_graph(Graph *G, int c[SIZE][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		G->V[i] = (Vortex*)malloc(sizeof(Vortex));
		for (j = 0; j < SIZE; j++){
			if (c[i][j] == 1)
				connect_vortex(G, i, j);
		}
	}
}
void connect_vortex(Graph *G, int u, int v) {
	Element *tmp_u = G->adj[u];
	Element *tmp_v;

	tmp_v = (Element*)malloc(sizeof(Element));
	tmp_v->index = v;
	tmp_v->next = NULL;

	if (tmp_u == NULL) G->adj[u] = tmp_v;
	else {
		while (tmp_u->next != NULL) tmp_u = tmp_u->next;
		tmp_u->next = tmp_v;
	}
}
void disconnect_vortex(Graph *G, int u, int v) {
	Element *tmp_u = G->adj[u];
	Element *tmp_v;

	if (tmp_u != NULL) {
		if (tmp_u->index == v) {
			tmp_v = tmp_u;
			tmp_u = tmp_u->next;
		}
		else {
			while (tmp_u->next->index != v) tmp_u = tmp_u->next;
			tmp_v = tmp_u->next;
			tmp_u->next = tmp_u->next->next;
		}
		free(tmp_v);
	}
}
void print_queue(Queue *Q){
	Element *tmp;

	printf("Queue : ");
	for (tmp = Q->head; tmp != NULL; tmp = tmp->next) printf("%d ", tmp->index);
	printf("\n");
}
void push_queue(Queue *Q, int i){
	Element *tmp;

	tmp = (Element*)malloc(sizeof(Element));
	tmp->index = i;
	tmp->next = NULL;

	if (Q->head == NULL) {
		Q->head = tmp;
		Q->tail = tmp;
	}
	else {
		Q->tail->next = tmp;
		Q->tail = tmp;
	}
}
int pop_queue(Queue *Q){
	Element *tmp_element;
	int tmp_index;

	if (Q->head == NULL) return -1;
	else {
		tmp_element = Q->head;
		tmp_index = Q->head->index;

		Q->head = Q->head->next;
		free(tmp_element);
		return tmp_index;
	}
}