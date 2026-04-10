#include <stdio.h> 
#include <stdlib.h> 

typedef struct node {
    int inf; 
    struct node * left; 
    struct node * right; 
}node; 

int pref [501];
int inf [501];
int posf [501];

int t = 0; 
int j = 0;
int k = 0; 

node * push (node *a, int v){
    if(!a){
        a = (node*)malloc(sizeof(node));
        a->inf = v; 
        a->left = a->right = NULL; 
    }
    else if (a->inf > v)
        a->left = push(a->left, v);
    else 
        a->right = push(a->right, v); 

    return a; 
}

void prefixa (node *a){    
    if(a){
        pref[t++] = a->inf; 
        prefixa(a->left);
        prefixa(a->right);
    }
}

void infixa (node *a){
    if(a){
        infixa(a->left);
        inf[j++] = a->inf; 
        infixa(a->right);
    }
}

void posfixa (node *a){
    if(a){
        posfixa(a->left);
        posfixa(a->right);
        posf[k++] = a->inf; 
    }
}

void printA(int *s, int n){
    int z; 
    for(z = 0; z < n; z++){
        if(!z)
            printf("%d", s[z]);
        else 
            printf(" %d", s[z]);
    }
    printf("\n");
}


int main () {
    int n, c = 1; 
    scanf("%d", &n);
    while(n--){        
        node *arv = NULL; 
        int m, i; 
        scanf("%d", &m);
        for(i=0; i<m; i++){
            int b; 
            scanf("%d", &b);
            arv = push(arv, b);
        }
        printf("Case %d:\n", c++); 
        printf("Pre.: ");
        prefixa (arv), printA(pref, t), t = 0; 
        printf("In..: ");
        infixa (arv), printA(inf, j), j = 0; 
        printf("Post: ");
        posfixa (arv), printA(posf, k), k = 0; 
        printf("\n");
    }
}
