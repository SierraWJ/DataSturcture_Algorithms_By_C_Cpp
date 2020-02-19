#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Print_Queue(int *Q, int *Q_head, int *Q_tail,int N) {
	int tmp_head;

	tmp_head = *Q_head;

	while (tmp_head != *Q_tail) {
		printf("%d ", Q[tmp_head]);
		if (tmp_head == N)
			tmp_head = 0;
		else
			tmp_head = tmp_head + 1;
	}
	printf("\n");
}
void enqueue(int *Q, int *Q_head, int *Q_tail, int N) {
	int x;
	printf("Input Number : ");
	scanf("%d",&x);
	if(*Q_tail <= N){
	Q[*Q_tail] = x;
	if (*Q_tail == N)
		printf("OverFlow!\n");
	else
		*Q_tail = *Q_tail + 1;
	}
}
int dequeue(int *Q, int *Q_head, int *Q_tail, int N) {
	int x;
	x = Q[*Q_head];
	if (*Q_head == N)
		printf("UnderFlow!\n");
	else
		*Q_head = *Q_head + 1;
	return x;
}
int main(void) {
	int x;
	int menu;
    int N;
    printf("Input Size of Queue :");
    scanf("%d",&N);
    int *Q = malloc(sizeof(int)*N);
    int Q_head = 0;
    int Q_tail = 0;
	while (1) {
		printf("select menu : \n");
		printf("0) inqueue\n");
		printf("1) dequeue\n");
		printf("default) exit\n");
		scanf("%d", &menu);
		if (menu == 0) {
			enqueue(Q,&Q_head,&Q_tail,N);
			Print_Q(Q,&Q_head,&Q_tail,N);
		}
		else if (menu == 1) {
			printf("dequeue : %d\n", dequeue(Q,&Q_head,&Q_tail,N));
			Print_Q(Q,&Q_head,&Q_tail,N);
		}
		else
			break;
	}
	return 0;
}
