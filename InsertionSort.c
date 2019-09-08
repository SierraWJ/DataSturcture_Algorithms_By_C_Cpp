#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Print_Array(int *Array, int *n){
	int i;
	for(i = 0; i < *n; i++) printf("%d ",Array[i]);
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
void Initialize_Array(int *Array,int N, int *n){
	*n = 0;
	int i;
	for(i = 0; i < N; i++){
		Array[i] = 0;
	}
}
void Insertion_Sort(int *Array, int *n){
	int i,j,k,key;
	int *IniArray = malloc(sizeof(int)*(*n));
	for(i = 0; i < *n; i++) IniArray[i] = Array[i];
	printf("Initial State of Array : ");
	for(k =0; k < *n ; k++) printf("%d ",IniArray[k]);
	printf("\n");
	for(j=1;j<*n;j++){
		printf("===================\n");
        	printf("Turn of %d Index\n",j);
		printf("===================\n");
		key = Array[j];
        	i = j - 1;
        while(i >= 0 && Array[i] > key){
            	Array[i+1] = Array[i];
		printf("Index %d and %d are changed\n",i,i+1);
		Print_Array(Array,n);
            	i = i - 1;
        }
        	Array[i+1] = key;
		system("pause");
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
        printf("========Insertion Sort Simulation========\n");
	printf("Status of Array : ");
	Print_Array(Array,&n);
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
		Initialize_Array(Array,N,&n);
                break;
            }
            case 3:{
                system("cls");
		Insertion_Sort(Array,&n);
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
	system("pause");
}
