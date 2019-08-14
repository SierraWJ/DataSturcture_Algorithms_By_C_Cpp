#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
void Merge(int *List, int p, int q, int r){
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = (int *)malloc(sizeof(int)*(n1 + 1));
    int *R = (int *)malloc(sizeof(int)*(n2 + 1));
    for (i = 0; i < n1; i++){
        L[i] = List[p + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = List[q + j + 1];
    }
    L[n1] = 9999;
    R[n2] = 9999;
    i = 0, j = 0;
    printf("Before\n");
    Print_List(List,8);
    Print_Partial_List(L,0,n1);
    Print_Partial_List(R,0,n2);
    for (k = p; k <= r; k++){
        printf("=====================\n");
        if (L[i] <= R[j]){
            printf("Left is smaller than Right\n");
            List[k] = L[i];
            i++;
        }
        else{
            printf("Right is smaller than Left\n");
            List[k] = R[j];
            j++;
        }
        Print_List(List,8);
        Print_Partial_List(L,0,n1);
        Print_Partial_List(R,0,n2);
        printf("=====================\n");
    }
    free(L);
    free(R);
}
void Merge_Sort(int *List, int p, int r){
    int q;
    if (p < r){
    q = (p + r) / 2;
    Merge_Sort(List, p, q);
    Merge_Sort(List, q + 1, r);
    Merge(List, p, q, r);
    }
}
int main(){
    int menu;
    int exit;
    int N;
    int n = 0;
    printf("Input Size of List : ");
    scanf("%d",&N);
    int *List = malloc(sizeof(int)*N);
	int i;
	for(i = 0; i < N; i++) List[i] = 0;
    system("cls");
    while(1){
        printf("========Merge Sort Simulation========\n");
		printf("Status of List : ");
		Print_List(List,n);
        printf("1) Input Number\n");
		printf("2) Initialization\n");
        printf("3) Sorting\n");
        printf("Default) Exit\n");
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
				Merge_Sort(List,0,n-1);
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
    free(List);
}
