#include <stdio.h> 
#include <stdlib.h> 

typedef struct node {
    char inf; 
    struct node * left; 
    struct node * right; 
}node ;

node *push (node *a, char c){
    if(!a){
        a = (node*)malloc(sizeof(node));
        a->inf = c;
        a->left = a->right = NULL; 
    }
    else if(a->inf > c)
        a->left = push (a->left, c);
    else 
        a->right = push (a->right, c);
}

int main () {
    
}