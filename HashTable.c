#include <stdio.h>
#include <stdlib.h>

int Direct_Address_Search(int T[], int k){
    return T[k];
}
void Direct_Address_Insert(int T[], int x, int key[]){
    T[key[x]] =x;
}
void Direct_Address_Delete(int T[], int x, int key[]){
    T[key[x]] = NULL;
}
void Chained_Hash_Insert(int T[], int x){

}
