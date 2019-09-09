#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Print_Array(int *Array, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ",Array[i]);
	}
	printf("\n");
}
void Print_Partial_Array(int *Array, int a, int b){
    int i;
    for(i = a; i < b; i++){
        printf("%d ",Array[i]);
    }
    printf("\n");
}
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
void Max_Heapify(int *Array, int i, int n, int N){
    int l = 2 * i + 1, r = 2 * i + 2, largest, tmp; //Left = 2 * i + 1 , Right = 2 * i + 2
    if (l <= n && Array[l]>Array[i]) largest = l;
    else largest = i;
    if (r <= n && Array[r] > Array[largest]) largest = r;
    if (largest != i){
        tmp = Array[i];
        Array[i] = Array[largest];
        Array[largest] = tmp;
        printf("========================================\n");
        Print_Array(Array,N);
        printf("%d index and %d index were swapped\n",i,largest);
        printf("========================================\n");
        Max_Heapify(Array, largest, n, N);
    }
}
void Build_Max_Heap(int *Array, int n, int N){
    int i;
    //parent(i) = i/2
    for( i = ((n-1)/2) ; i >= 0 ; i--) Max_Heapify(Array,i,n,N);
    printf("========================================\n");
    printf("Max Heap was builded\n");
    Print_Array(Array,N);
    printf("========================================\n");
}
void Heap_Sort(int *Array, int n){
    int i, tmp;
    int N = n;
    printf("HeapSort Function was called\n");
    Build_Max_Heap(Array, n-1,N);
    for (i = n; i >=1 ; i--){
        tmp = Array[0];
        Array[0] = Array[i];
        Array[i] = tmp;
        Max_Heapify(Array,0,i - 1, N);
   }
   system("pause");
}
int main(){
    int i,n,N;
    int menu;
    int exit;
    printf("Input size of Array : ");
    scanf("%d",&N);
    int *Array = malloc(sizeof(int)*N);
    n = 0;
    system("cls");
    while(1){
        printf("========Heap Sort Simulation========\n");
        printf("Array : ");
        Print_Array(Array,n);
        printf("1) Input Number\n");
        printf("2) Initialization\n");
        printf("3) Sorting\n");
        printf("Default) Exit\n");
        printf("Selece menu : ");
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
                Heap_Sort(Array,n-1);
                break;
            }
            default:{
                exit = 0;
                break;
            }
        }
        system("cls");
        if(exit == 0) break;
    }
    free(Array);
}
