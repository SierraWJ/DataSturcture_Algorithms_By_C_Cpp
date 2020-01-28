#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define SWAP(a,b) {int t; t=a; a=b; b=t;}
void Input_Array(int *Array, int N, int *n){
    if(*n < N){
        int num;
        printf("Input Number : ");
        scanf("%d",&num);
        Array[*n] = num;
        *n += 1;
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
int Maximum_Num_In_Array(int A[], int N){
    int i;
    int Maximum = -999;
    for(i = 0; i < N; i++){
        if(A[i] >= Maximum) SWAP(A[i], Maximum); 
    }
    return Maximum;
}
void Counting_Sort(int *A, int *B, int k, int length){
    int *C = malloc(sizeof(int)*(k + 1));
    int i, j;
    printf("===========================================\n");
    printf("Before Sorting : ");
    Print_Array(A,length);
    for (i = 0; i <= k; i++) C[i] = 0;
    for (j = 0; j < length; j++) C[A[j]] = C[A[j]] + 1;
    printf("State of C Array (phase 1) : ");
    Print_Array(C,length);
    for (i = 1; i <= k; i++) C[i] = C[i] + C[i - 1];
    printf("State of C Array (phase 2) : ");
    Print_Array(C,length);
    printf("===========================================\n");
    printf("Start Sorting Process\n");
    for (j = length - 1; j >= 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
        printf("State of A Array :");
        Print_Array(A,length);
        printf("State of B Array :");
        Print_Array(B,length);
        printf("State of C Array :");
        Print_Array(C,length);
    }
    for(i = 0; i < length; i++) SWAP(A[i],B[i]);
    free(C);
}
int main(){
    int menu;
    int exit;
    int N;
    int n = 0;
    printf("Input Size of Array : ");
    scanf("%d",&N);
    int *Array = malloc(sizeof(int)*N);
    int *B_Array = malloc(sizeof(int)*N);
	int i;
	for(i = 0; i < N; i++) Array[i] = 0;
    system("cls");
    while(1){
        printf("========Counting Sort Simulation========\n");
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
				Input_Array(Array,N,&n);
                break;
            }
            case 2:{
                system("cls");
				Initialization_Array(Array,N,&n);
                Initialization_Array(B_Array,N,&n);
                break;
            }
            case 3:{
                system("cls");
				Counting_Sort(Array, B_Array,Maximum_Num_In_Array(Array,N),n);
                Initialization_Array(B_Array,N,&n);
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
    free(B_Array);
}
