#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Print_Queue(int *Q, int *Q_head, int *Q_tail,int N) {
	if(*Q_head != *Q_tail){
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
}
void enqueue(int *Q, int *Q_head, int *Q_tail, int N) {
	int x;
	printf("Input Number : ");
	scanf("%d",&x);
	Q[*Q_tail] = x;
    	if (*Q_tail == N) {
        	if(*Q_head == 0) printf("OverFlow!\n");
        	else *Q_tail = 0;
    	}
    	else if(*Q_tail + 1 == *Q_head) printf("OverFlow!\n");
		else *Q_tail = *Q_tail + 1;
	}
}
int dequeue(int *Q, int *Q_head, int *Q_tail, int N) {
	if(*Q_head == *Q_tail) printf("Underflow!\n");
    	else{
        	int x;
	    	x = Q[*Q_head];
	    	if (*Q_head == N) *Q_head = 0;
	    	else{
            	x = Q[*Q_head];
 	    	*Q_head = *Q_head + 1;
             	return x;
	}
   }
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
		printf("0) Enqueue\n");
		printf("1) Dequeue\n");
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
