#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define size 1000100
typedef struct node {
    char *s; 
    struct node * left; 
    struct node * right; 
}node; 

int q = 0; 

node * push (node *a, char *s){    

    if(!a){
        q++; 
        a = (node*) malloc (sizeof(node));     
        a->s = (char*) calloc(strlen(s), sizeof(char));  
        strcpy (a->s, s);
        a->left = a->right = NULL; 
    }

    else if(strcmp(a->s, s) >  0)
        a->left = push (a->left, s);
    else if(strcmp(a->s, s) < 0)
        a->right = push (a->right, s);
    
    return a; 

}

int main () {
    char s[size];     
    node *arv = NULL;    
    while(~scanf("%s", s))
         arv = push(arv, s);
    
    printf("%d\n", q);
}