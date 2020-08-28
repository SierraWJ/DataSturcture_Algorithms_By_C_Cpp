#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

#define WHITE	0
#define GRAY	1
#define BLACK	2

#define INF		-1

typedef struct _Vortex {
	int color;
	int d;
	int f;
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

void print_path(Graph *G, int s, int v);
void depth_first_search(Graph *G);
void depth_first_search_visit(Graph *G, int u, int *time);
void print_graph(Graph *G);
void init_graph(Graph *G, int c[SIZE][SIZE]);
void connect_vortex(Graph *G, int u, int v);
void disconnect_vortex(Graph *G, int u, int v);
int main(void) {
	Graph G = { 0 };
	int c[SIZE][SIZE] = {
		{ 0, 1, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 1, 1 },
		{ 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 1 },
	};
	init_graph(&G, c);
	depth_first_search(&G);
	printf("Path : ");
	print_path(&G, 1, 3);
	printf("\n");
	return 0;
}
void print_path(Graph *G, int s, int v) {
	if (v == s) printf("%d ", s);
	else if (G->V[v]->parent == -1) printf("no path\n");
	else {
		print_path(G, s, G->V[v]->parent);
		printf("%d ", v);
	}
}
void depth_first_search(Graph *G){
	int u;
	int time;

	for (u = 0; u < SIZE; u++) {
		G->V[u]->color = WHITE;
		G->V[u]->d = INF;
		G->V[u]->f = INF;
		G->V[u]->parent = -1;
	}
	time = 0;
	for (u = 0; u < SIZE; u++) {
		if (G->V[u]->color == WHITE)
			depth_first_search_visit(G, u, &time);
	}
}
void depth_first_search_visit(Graph *G, int u, int *time) {
	Element *tmp;
	int v;

	*time = *time + 1;
	G->V[u]->d = *time;
	G->V[u]->color = GRAY;

	print_graph(G);
	printf("\n");
	for (tmp = G->adj[u]; tmp != NULL; tmp = tmp->next) {
		v = tmp->index;
		if (G->V[v]->color == WHITE) {
			G->V[v]->parent = u;
			depth_first_search_visit(G, v, time);
		}
	}
	G->V[u]->color = BLACK;
	*time = *time + 1;
	G->V[u]->f = *time;
	print_graph(G);
	printf("\n");
}
void print_graph(Graph *G) {
	int i;

	printf("Color : ");
	for (i = 0; i < SIZE; i++) printf("%d ", G->V[i]->color);
	printf("\n");
	printf("d/f : ");
	for (i = 0; i < SIZE; i++) printf("%2d/%2d ", G->V[i]->d, G->V[i]->f);
	printf("\n");
}
void init_graph(Graph *G, int c[SIZE][SIZE]) {
	int i, j;

	for (i = 0; i < SIZE; i++) {
		G->V[i] = (Vortex*)malloc(sizeof(Vortex));
		for (j = 0; j < SIZE; j++) {
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