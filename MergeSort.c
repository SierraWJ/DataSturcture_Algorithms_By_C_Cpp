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
void Merge(int A[], int p, int q, int r){
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = (int *)malloc(sizeof(int)*(n1 + 1));
    int *R = (int *)malloc(sizeof(int)*(n2 + 1));
    for (i = 0; i < n1; i++){
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = A[q + j + 1];
    }
    L[n1] = 9999;
    R[n2] = 9999;
    i = 0, j = 0;
    printf("Before\n");
    Print_Array(A,8);
    Print_Partial_Array(L,0,n1);
    Print_Partial_Array(R,0,n2);
    for (k = p; k <= r; k++){
        printf("=====================\n");
        if (L[i] <= R[j]){
            printf("Left is smaller than Right\n");
            A[k] = L[i];
            i++;
        }
        else{
            printf("Right is smaller than Left\n");
            A[k] = R[j];
            j++;
        }
        Print_Array(A,8);
        Print_Partial_Array(L,0,n1);
        Print_Partial_Array(R,0,n2);
        printf("=====================\n");
    }
    free(L);
    free(R);
}
void Mergesort(int A[], int p, int r){
    int q;
    if (p < r){
    q = (p + r) / 2;
    Mergesort(A, p, q);
    Mergesort(A, q + 1, r);
    Merge(A, p, q, r);
    }
}
int main(){
    int i;
    int A[8] = { 2, 4, 5, 7, 1, 2, 3, 6 };
    printf("Before MergeSort : ");
    for (i = 0; i < 8; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    int p = 0, r = 7;
    Mergesort(A, p, r);
    printf("After MergeSort : ");
    for (i = 0; i < 8; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    system("pause");
}
