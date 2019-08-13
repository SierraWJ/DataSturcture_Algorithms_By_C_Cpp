#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Print_List(int *List, int *n){
	int i;
	for(i = 0; i < *n; i++){
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
void Initialize_List(int *List,int N, int *n){
	*n = 0;
	int i;
	for(i = 0; i < N; i++){
		List[i] = 0;
	}
}
void Insertion_Sort(int *List, int *n){
	int i,j,k,key;
	int *IniList = malloc(sizeof(int)*(*n));
	for(i = 0; i < *n; i++) IniList[i] = List[i];
	printf("Initial State of List : ");
	for(k =0; k < *n ; k++) printf("%d ",IniList[k]);
		printf("\n");
	for(j=1;j<*n;j++){
		printf("===================\n");
        printf("Turn of %d Index\n",j);
		printf("===================\n");
		key = List[j];
        i = j - 1;
        while(i >= 0 && List[i] > key){
            List[i+1] = List[i];
			printf("Index %d and %d are changed\n",i,i+1);
			Print_List(List,n);
            i = i - 1;
        }
        List[i+1] = key;
		system("pause");
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
    while(1){
        printf("========Insertion Sort Simulation========\n");
		printf("Status of List : ");
		Print_List
    (List,&n);
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
				Initialize_List(List,N,&n);
                break;
            }
            case 3:{
                system("cls");
				Insertion_Sort(List,&n);
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
