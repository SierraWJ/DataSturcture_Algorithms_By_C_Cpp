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
int Partition(int *Array,int p, int r, int N){
    int pivot = Array[r];
    int i = p - 1;
    int j;
    int n = r-p + 1;
    printf("================================================================\n");
    printf("Status of Array : ");
    Print_Array(Array,N);
    printf("Now pivot index is %d\n",r);
    for(j = p; j <= r-1; j++){
        if(Array[j] <= pivot){
            i = i + 1;
            SWAP(Array[i],Array[j]);
            printf("Index %d and %d was swapped\n",i,j);
            Print_Partial_Array(Array,p,r);
        }
    }
    SWAP(Array[i+1],Array[r]);
    printf("Partition Complete\n");
    Print_Array(Array,N);
    printf("Less than Pivot : index between %d and %d\n",p,i);
    printf("Bigger than Pivot : index between %d and %d\n",i+2,r);
    printf("================================================================\n");
    
    return i + 1;
}
void Quicksort(int *Array,int p, int r, int N){
    int q;
    if(p < r){
        q = Partition(Array,p,r,N);
        Quicksort(Array,p,q-1,N);
        Quicksort(Array,q+1,r,N);
    }
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
        printf("========Quick Sort Simulation========\n");
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
				Quicksort(Array,0,n-1,N);
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
