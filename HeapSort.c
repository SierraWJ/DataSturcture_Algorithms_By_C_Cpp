#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int staticNUM;

void Print_List(int *List, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ",List[i]);
	}
	printf("\n");
}
void Print_Partial_List(int *List, int a, int b){
    int i;
    for(i = a; i < b; i++){
        printf("%d ",List[i]);
    }
    printf("\n");
}
void Input_List(int *List, int N, int *n){
    if(*n < N){
        int num;
        printf("Input Number : ");
        scanf("%d",&num);
        List[*n] = num;
        *n += 1;
    }
    else{
        printf("OverFlow!\n");
        system("pause");
    }
}
void Initialization_List(int *List,int N, int *n){
	*n = 0;
	int i;
	for(i = 0; i < N; i++){
		List[i] = 0;
	}
}
void Max_Heapify(int *List, int i, int n){
    int l = 2 * i + 1, r = 2 * i + 2, largest, tmp; //Left = 2 * i + 1 , Right = 2 * i + 2
    if (l <= n && List[l]>List[i]) largest = l;
    else largest = i;
    if (r <= n && List[r] > List[largest]) largest = r;
    if (largest != i){
        tmp = List[i];
        List[i] = List[largest];
        List[largest] = tmp;
        Print_List(List,staticNUM);
        printf("%d index and %d index were swapped\n",i,largest);
        Max_Heapify(List, largest, n);
    }
}
void Build_Max_Heap(int *List, int n){
    int i;
    //parent(i) = i/2
    for( i = ((n-1)/2) ; i >= 0 ; i--) Max_Heapify(List,i,n);
    printf("Max Heap was builded\n");
    Print_List(List,staticNUM);
}
void Heap_Sort(int *List, int n){
    int i, tmp;
    printf("Before Sorting : ");
    Print_List(List,n);
    Build_Max_Heap(List, n-1);
    for (i = n; i >=1 ; i--){
        tmp = List[0];
        List[0] = List[i];
        List[i] = tmp;
        Max_Heapify(List,0,i - 1);
   }
   system("pause");
}
int main(){
    int i,n,N;
    int menu;
    int exit;
    printf("Input size of List : ");
    scanf("%d",&N);
    int *List = malloc(sizeof(int)*N);
    n = 0;
    system("cls");
    while(1){
        printf("========Heap Sort Simulation========\n");
        printf("List : ");
        Print_List(List,n);
        staticNUM = n;
        printf("1) Input Number\n");
        printf("2) Initialization\n");
        printf("3) Sorting\n");
        printf("Default) Exit\n");
        printf("Selece menu : ");
        scanf("%d",&menu);
        switch(menu){
            case 1:{
                system("cls");
                Input_List(List,N,&n);
                break;
            }
            case 2:{
                system("cls");
                Initialization_List(List,N,&n);
                break;
            }
            case 3:{
                system("cls");
                Heap_Sort(List,n-1);
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
    free(List);
}
