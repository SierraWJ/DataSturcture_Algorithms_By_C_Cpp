#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int key;
    struct _Node *right;
    struct _Node *left;
}Node;

void node_insert(Node **node, Node **free, int key);
void node_delete(Node **node, Node **free, int key);
void node_print(Node *node);
void free_print(Node *free);

int main(){
    Node *root;
    Node *free;
    int i;

    root = NULL;
    free = NULL;

}
void node_insert(Node **node, Node **free, int key){
    Node *x = *node;
    Node *tmp;

    if(*free == NULL) tmp = (Node*)malloc(sizeof(Node));
    else{
        tmp = *free;
        *free = (*free)->right;
    }
    tmp->key = key;
    tmp->left = NULL;
    tmp->right = NULL;

    if(x == NULL) *node = tmp;
    else{
        while(1){
            if(x->key > key){
                if(x->key == NULL){
                    x->left = tmp;
                    break;
                }
                else x = x->left;
            }
            else{
                if(x->right == NULL){
                    x->right = tmp;
                    break;
                }
                else x = x -> right;
            }
        }
    }

}

void node_delete(Node **node, Node **free, int key){
    Node *x = *node;
    Node *tmp;

    if(x->key == key){
        if(x->left != NULL){
            tmp = x->left;
            while(tmp->right != NULL) tmp = tmp->right;
            tmp->right = x->right;
            *node = x->right;
        
        }
        else if (x->right != NULL){
            tmp = x->right;
            while(tmp->left != NULL) tmp = tmp->left;
            tmp -> left = x -> left;
            *node = NULL;
        }
        else{
            *node = NULL;
        }
        tmp = x;
    }
    else{
        while(1){
            if(x->key > key){
                if(x->left->key != key) x = x -> left;
                else{
                    if(x->left->left != NULL){
                        tmp = x->left->left;
                        while(tmp->right != NULL) tmp = tmp->right;
                        tmp->right = x->left->right;

                        tmp = x->left;
                        x->left = x->left->left;
                    }
                    else{
                        tmp = x->left;
                        x->left = NULL;
                    }
                    break;
                }
            }
            else if(x->key < key){
                if(x->right->key != key) x= x->right;
                else{
                    if(x->right->left != NULL){
                        tmp = x->right->left;
                        while(tmp->right!=NULL) tmp = tmp -> right;
                        tmp->right = x->right->right;

                        tmp = x->right;
                        x->right = x->right->left;
                    }
                    else if(x->right->right!=NULL){
                        tmp = x->right->right;
                        while(tmp->left != NULL)tmp = tmp->left;
                        tmp->left = x->right->left;

                        tmp = x->right;
                        x->right = x->right->right;
                    }
                    else{
                        tmp = x->right;
                        x->right = NULL;
                    }
                    break;
                    }
                }
            }
        }
        tmp->right = *free;
        *free = tmp;
}
void node_print(Node *node){
if (node != NULL) {
		node_print(node->left);
		printf("%d ", node->key);
		node_print(node->right);
	}
}
void free_print(Node *free){
if (free != NULL) {
		printf("%d ", free->key);
		free_print(free->right);
	}
}