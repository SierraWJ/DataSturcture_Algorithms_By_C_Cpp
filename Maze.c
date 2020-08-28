#include <stdio.h>
#include <stdlib.h>

#define HEIGHT	7
#define WIDTH	7

#define N	0
#define NE	1
#define E	2
#define SE	3
#define S	4
#define SW	5
#define W	6
#define NW	7

typedef struct _Infor {
	int x;
	int y;
	int direction;
}Infor;

typedef struct _Node {
	Infor *infor;
	struct _Node *next;
}Node;

typedef struct _Stack {
	Node *top;
}Stack;

void move(int maze[HEIGHT][WIDTH], int mark[HEIGHT][WIDTH], Stack *stack);

Infor *create_infor(int x, int y, int direction);
void delete_infor(Infor *infor);

Stack *create_stack(void);
void delete_stack(Stack *stack);
void init_stack(Stack *stack);
int empty_stack(Stack *stack);
void push_stack(Stack *stack, Infor *infor);
Infor *pop_stack(Stack *stack);
void print_stack(Stack *stack);

int main(void) {
	int maze[HEIGHT][WIDTH] = {
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 0, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1}
	};
	int mark[HEIGHT][WIDTH] = { 0 };
	Stack *stack;
	Infor *infor;
	int i, j;

	stack = create_stack();
	infor = create_infor(1, 1, N);
	mark[1][1] = 1;

	push_stack(stack, infor);
	move(maze, mark, stack);

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) 
			printf("%d ", mark[i][j]);
		printf("\n");
	}

	return 0;
}
void move(int maze[HEIGHT][WIDTH], int mark[HEIGHT][WIDTH], Stack *stack) {
	Infor *infor, *tmp_infor;

	infor = stack->top->infor;
	if (infor->x == HEIGHT - 2 && infor->y == WIDTH - 2) {
		print_stack(stack);
		return;
	}
	tmp_infor = create_infor(infor->x, infor->y, infor->direction);
	if (infor->direction == NW || infor->direction == N || infor->direction == NE)
		tmp_infor->x -= 1;
	else if (infor->direction == SE || infor->direction == S || infor->direction == SW)
		tmp_infor->x += 1;
	if (infor->direction == NE || infor->direction == E || infor->direction == SE)
		tmp_infor->y += 1;
	else if (infor->direction == SW || infor->direction == W || infor->direction == NW)
		tmp_infor->y -= 1;
	tmp_infor->direction = N;

	if (mark[tmp_infor->x][tmp_infor->y] == 0 && maze[tmp_infor->x][tmp_infor->y] == 0) {
		mark[tmp_infor->x][tmp_infor->y] = 1;
		push_stack(stack, tmp_infor);
		move(maze, mark, stack);
	}
	else {
		delete_infor(tmp_infor);
		tmp_infor = pop_stack(stack);
		if (tmp_infor->direction == NW) {
			delete_infor(tmp_infor);
			move(maze, mark, stack);
		}
		else {
			tmp_infor->direction += 1;
			push_stack(stack, tmp_infor);
			move(maze, mark, stack);
		}
	}
}
Infor *create_infor(int x, int y, int direction) {
	Infor *tmp_infor;

	tmp_infor = (Infor*)malloc(sizeof(Infor));
	tmp_infor->x = x;
	tmp_infor->y = y;
	tmp_infor->direction = direction;

	return tmp_infor;
}
void delete_infor(Infor *infor) {
	free(infor);
}
Stack *create_stack(void) {
	Stack *tmp_stack;

	tmp_stack = (Stack*)malloc(sizeof(Stack));
	tmp_stack->top = NULL;

	return tmp_stack;
}
void delete_stack(Stack *stack) {
	free(stack);
}
void init_stack(Stack *stack) {
	Infor *infor;

	while (!empty_stack(stack)) {
		infor = pop_stack(stack);
		delete_infor(infor);
	}
}
int empty_stack(Stack *stack) {
	if(stack->top == NULL) return 1;
	else return 0;
}
void push_stack(Stack *stack, Infor *infor){
	Node *tmp_node;

	tmp_node = (Node*)malloc(sizeof(Node));
	tmp_node->infor = infor;
	tmp_node->next = stack->top;

	stack->top = tmp_node;
}
Infor *pop_stack(Stack *stack){
	Infor *tmp_infor;
	Node *tmp_node;
	
	tmp_infor = stack->top->infor;
	tmp_node = stack->top;

	stack->top = stack->top->next;
	free(tmp_node);
	return tmp_infor;
}
void print_stack(Stack *stack) {
	Node *tmp_node;

	tmp_node = stack->top;
	while (tmp_node != NULL) {
		printf("< %d , %d , %d >\n",
			tmp_node->infor->x,
			tmp_node->infor->y,
			tmp_node->infor->direction);
		tmp_node = tmp_node->next;
	}
}