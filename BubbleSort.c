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
void Print_Partial_Array(int *Array, int a, int b){
    int i;
    for(i = a; i <= b; i++){
        printf("%d ",Array[i]);
    }
    printf("\n");
}
void bubbleSort(int *Array, int n){
    int i,j;
    printf("Before Bubblesort : ");
    printf("=======================================\n");
    Print_Array(Array,n);
    for (i = n-1 ; i > 0 ; i--){
        for (j = 0 ; j < i ; j++){
            if (Array[j] > Array[j+1]){
                SWAP(Array[j],Array[j+1]); //#define SWAP(a,b) {int t; t=a; a=b; b=t;}
                printf("Index %d and %d was swapped\n",i,j);
                Print_Array(Array,n);
            }
        }
    }
    printf("=======================================\n");
    printf("After Bubblesort : ");
    Print_Array(Array,n);
}
int main(){
    int menu;
    int exit;
    int N;
    int n = 0;
    printf("Input Size of Array : ");
    scanf("%d",&N);
    int *Array = malloc(sizeof(int)*N);
	int i;
	for(i = 0; i < N; i++) Array[i] = 0;
    system("cls");
    while(1){
        printf("========Bubble Sort Simulation========\n");
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
                break;
            }
            case 3:{
                system("cls");
				bubbleSort(Array,n);
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
