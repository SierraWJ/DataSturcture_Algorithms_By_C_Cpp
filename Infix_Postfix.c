#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	char ch;
	struct _Node *next;
}Node;

typedef struct _Stack {
	Node *top;
}Stack;

typedef struct _Queue {
	Node *head;
	Node *tail;
}Queue;

int precedence(char ch);
Queue *infix_to_prefix(Queue *infix);
int evaluate_postfix(Queue *postfix);

Stack *create_stack(void);
void delete_stack(Stack *stack);
void init_stack(Stack *stack);
int empty_stack(Stack *stack);
void push_stack(Stack *stack, char ch);
char pop_stack(Stack *stack);
void print_stack(Stack *stack);

Queue *create_queue(void);
void delete_queue(Queue *queue);
void init_queue(Queue *queue);
int empty_queue(Queue *queue);
void push_queue(Queue *queue, char ch);
char pop_queue(Queue *queue);
void print_queue(Queue *queue);

int main(void) {
	Queue *infix;
	Queue *postfix;
	char ch;

	infix = create_queue();
	printf("infix : ");
	while (1) {
		scanf("%c", &ch);
		if (ch == '\n')
			break;
		else
			push_queue(infix, ch);
	}

	postfix = infix_to_prefix(infix);
	printf("postfix : ");
	print_queue(postfix);
	printf("evaluate : %d\n", evaluate_postfix(postfix));
	return 0;
}
int precedence(char ch) {
	switch (ch) {
	case '(': return 0;
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	}
	return -1;
}
Queue *infix_to_prefix(Queue *infix) {
	Queue *postfix;
	Stack *op;
	char q;
	int i = 0;

	postfix = create_queue();
	op = create_stack();
	while (!empty_queue(infix)) {
		q = pop_queue(infix);

		if (q >= '0' && q <= '9')
			push_queue(postfix, q);
		else if (q == '(')
			push_stack(op, q);
		else if (q == ')') {
			while (op->top->ch != '(')
				push_queue(postfix, pop_stack(op));
			pop_stack(op);
		}
		else {
			while (!empty_stack(op) && (precedence(q) <= precedence(op->top->ch)))
				push_queue(postfix, pop_stack(op));
			push_stack(op, q);
		}
	}
	while (!empty_stack(op))
		push_queue(postfix, pop_stack(op));
	delete_stack(op);
	return postfix;
}
int evaluate_postfix(Queue *postfix) {
	Stack *op;
	char x, y;
	char q;

	op = create_stack();
	while (!empty_queue(postfix)) {
		q = pop_queue(postfix);
		if (q >= '0' && q <= '9')
			push_stack(op, q);
		else {
			x = pop_stack(op) - '0';
			y = pop_stack(op) - '0';
			switch (q) {
			case '+':
				q = y + x;
				break;
			case '-':
				q = y - x;
				break;
			case '*':
				q = y*x;
				break;
			case '/':
				q = y / x;
				break;
			}
			push_stack(op, q + '0');
		}
	}
	q = pop_stack(op) - '0';
	delete_stack(op);
	return (int)q;
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
	while (!empty_stack(stack))
		pop_stack(stack);
}
int empty_stack(Stack *stack) {
	if (stack->top == NULL) return 1;
	else return 0;
}
void push_stack(Stack *stack, char ch) {
	Node *tmp_node;

	tmp_node = (Node*)malloc(sizeof(Node));
	tmp_node->ch = ch;
	tmp_node->next = stack->top;

	stack->top = tmp_node;
}
char pop_stack(Stack *stack) {
	char ch;
	Node *tmp_node;

	ch = stack->top->ch;
	tmp_node = stack->top;

	stack->top = stack->top->next;
	free(tmp_node);
	return ch;
}
void print_stack(Stack *stack) {
	Node *tmp_node;

	tmp_node = stack->top;
	while (tmp_node != NULL) {
		printf("%c ",tmp_node->ch);
		tmp_node = tmp_node->next;
	}
	printf("\n");
}
Queue *create_queue(void) {
	Queue *tmp_queue;

	tmp_queue = (Queue*)malloc(sizeof(Queue));
	tmp_queue->head = NULL;
	tmp_queue->tail = NULL;

	return tmp_queue;
}
void delete_queue(Queue *queue){
	free(queue);
}
void init_queue(Queue *queue) {
	while (!empty_queue(queue))
		pop_queue(queue);
}
int empty_queue(Queue *queue) {
	if (queue->head == NULL) return 1;
	else return 0;
}
void push_queue(Queue *queue, char ch) {
	Node *tmp_node;

	tmp_node = (Node*)malloc(sizeof(Node));
	tmp_node->ch = ch;
	tmp_node->next = NULL;

	if (empty_queue(queue)) {
		queue->head = tmp_node;
		queue->tail = tmp_node;
	}
	else {
		queue->tail->next = tmp_node;
		queue->tail = tmp_node;
	}
}
char pop_queue(Queue *queue) {
	char ch;
	Node *tmp_node;

	ch = queue->head->ch;
	tmp_node = queue->head;

	queue->head = queue->head->next;
	free(tmp_node);
	return ch;
}
void print_queue(Queue *queue) {
	Node *tmp_node;

	tmp_node = queue->head;
	while (tmp_node != NULL) {
		printf("%c ", tmp_node->ch);
		tmp_node = tmp_node->next;
	}
	printf("\n");
}