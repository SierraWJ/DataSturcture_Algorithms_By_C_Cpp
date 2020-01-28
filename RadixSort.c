#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define SWAP(a,b) {int t; t=a; a=b; b=t;}

int get_digit(int n, int d) {
	int i;
	for (i = 0; i < d; i++)
		n /= 10;
	return n % 10;
}
int get_ciper(int A){
    int i = 1;
	int ciper = 0;
    if(A>0){
		while(A/i != 0){
			i = i * 10;
			ciper++;
		}
		return ciper;
    }
    else return 0;
}
void Input_Array_RadixSort(int * Array, int N, int *n, int ciper){
    if(*n < N){
        int num;
        printf("Input Number : ");
        scanf("%d",&num);
        if(get_ciper(num) == ciper){
            Array[*n] = num;
            *n += 1;
        }
        else{
            printf("Don't input valid number\n");
            system("pause");
        }
    }
    else{
        printf("OverFlow!\n");
        system("pause");
    }
}
void Initialization_Array(int *Array,int N, int *n){
	*n = 0;
	int i;
	for(i = 0; i < N; i++){
		Array[i] = 0;
	}
}
void Print_Array(int *Array, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ",Array[i]);
	}
	printf("\n");
}
void Print_Array_2_Vertical(int *Array, int n){
    int i;
	for(i = 0; i < n; i++){
		printf("%d\n",Array[i]);
	}
	printf("\n");
}
void digit_based_counting_sort(int *A, int *B, int n, int digit) {
	int C[10];
	int tmp;
	int i;

	for (i = 0; i < 10; i++) C[i] = 0;
	for (i = 0; i < n; i++) {
		tmp = get_digit(A[i], digit);
		C[tmp] = C[tmp] + 1;
	}
	for (i = 1; i < 10; i++) C[i] = C[i] + C[i - 1];
	for (i = n - 1; i >= 0; i--) {
		tmp = get_digit(A[i], digit);
		B[C[tmp] - 1] = A[i];
		C[tmp] = C[tmp] - 1;
	}
}
void Radix_Sort(int *A, int n, int d) {
	int *B;
	int i, j;

	B = malloc(sizeof(int)*n);

	for (i = 0; i < d; i++) {
		digit_based_counting_sort(A, B, n, i);
		for (j = 0; j < n; j++)
			A[j] = B[j];
	}
    Print_Array_2_Vertical(A,n);
	free(B);
}

int main(){
    int menu;
    int exit;
    int N;
    int n = 0;
    int ciper;
    printf("Input Size of Array : ");
    scanf("%d",&N);
    printf("Input Ciper (ex : 100 => 3, 10 => 2) : ");
    scanf("%d",&ciper);
    int *Array = malloc(sizeof(int)*N);
	Initialization_Array(Array,N,&n);
    system("cls");
    while(1){
        printf("========Radix Sort Simulation========\n");
		printf("Status of Array : ");
		Print_Array(Array,n);
        printf("1) Input Number\n");
		printf("2) Initialization\n");
        printf("3) Sorting\n");
        printf("Default) Exit\n");
        scanf("%d",&menu);
        switch(menu){
            case 1:{
                system("cls");
				Input_Array_RadixSort(Array,N,&n,ciper);
                break;
            }
            case 2:{
                system("cls");
				Initialization_Array(Array,N,&n);
                break;
            }
            case 3:{
                system("cls");
				Radix_Sort(Array,n,ciper);
                system("pause");
                break;
            }
            default :{
                exit = 0;
                break;
            }
        }
        system("cls");
        if(exit == 0) break;
    }
    free(Array);
}

