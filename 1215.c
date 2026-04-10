#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h> 
#include <string.h> 

typedef struct arv {
    char s [201];
    struct arv*left; 
    struct arv*right; 
}arv;

arv *push (arv *a, char *s){
    if(!a){
        a = (arv*) malloc(sizeof(arv));
        strcpy(a->s, s); 
        a->left = a->right = NULL;
    }
    else if(strcmp(a->s, s) > 0)
        a->left = push(a->left, s);
    else if(strcmp(a->s, s) < 0)
        a->right = push(a->right, s);
    return a; 
}

void infixa(arv *a) {
	if (a) {
		infixa(a->left);
		printf("%s\n", a->s);
		infixa(a->right);
	}

}

int main () {
    char p, aux[300];
    arv *a  = NULL; 
    int cont = 0;
    while((p = getchar()) != EOF){
        if(isalpha(p))
            aux[cont++] = tolower(p);            
        else if(cont>0) {                
            aux[cont] = 0;    
            cont = 0;
            a = push(a, aux);              
        }                           
    }
    
    infixa(a);
    
    
}

