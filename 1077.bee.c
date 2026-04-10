#include <stdio.h> 
#include <stdlib.h> 
typedef struct nodo {
    int inf; 
    struct nodo * next; 
}NODO; 
typedef NODO * PILHA_ENC; 

void create (PILHA_ENC *p){
    *p = NULL; 
}

int is_empty (PILHA_ENC p){
    return (!p);
}

void push (PILHA_ENC *p, int v){
    NODO *novo = (NODO*)malloc(sizeof(NODO));
    if(!novo){
        printf("Erro na alocacao!\n");
        exit(1);
    }
    novo->inf = v;        
    novo->next = *p; 
    *p = novo;     
}

int top (PILHA_ENC p){
    if(!p){
        printf("Erro! A pilha esta vazia!\n");
        exit(2);
    }
    return p->inf; 
}

void pop (PILHA_ENC *p) {    
    if(!p){
        printf("Erro! A pilha esta vazia!\n");
        exit(2);
    }
    else {
        NODO *aux = *p; 
        *p = (*p)->next; 
        free(aux);
    }
}

int top_pop (PILHA_ENC *p){
    if(!p){
        printf("Erro! A lista esta vazia!\n");
        exit(2);
    }
    else {
        int v = (*p)->inf; 
        NODO *aux = *p;
        *p = (*p)->next;
        free(aux);
        return v; 
    }
}

void destroy (PILHA_ENC p){
    NODO *aux;
    while(p){
        aux = p; 
        p = p->next; 
        free(aux);        
    }
}

int is_operating (char op){
    return (op != '+' && op != '-' && op != '/' && op != '*' && op != '^' && op != '(' && op != ')');
}

int precedence (char op1, char op2){
    if((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-'))
        return 1; 
    if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/' || op2 == '+' || op2 == '-'))
        return 1; 
    if(op1 == '^' && (op2 == '^' || op2 == '*' || op2 == '/' || op2 == '+' || op2 == '-'))
        return 1; 
    if((op1 == '+' || op1 == '-' || op1 == '/' || op1 == '*' || op1 == '^') && op2 == ')' )
        return 1; 
    return 0;
}



int main () {
    int n;
    scanf("%d%*c", &n);
    
    while(n--){

        char o, str[301], str2[301];
        int i = 0, conts2 = 0; 
        PILHA_ENC p_op; 
        create(&p_op);
        scanf("%[^\n]", str);
        getchar();
        while(o = str[i++]){
            if(is_operating(o))
                str2[conts2++] = o;
            else {
                while(!is_empty(p_op) && precedence(top(p_op), o))
                    str2[conts2++] = (char) top_pop (&p_op);
                if(o == ')')
                    pop(&p_op);
                else 
                    push(&p_op, o);
            }
        }   
        while(!is_empty(p_op))
            str2[conts2++] = (char) top_pop (&p_op);
        str2[conts2] = '\0';
    
        printf("%s\n", str2);
    }
    
    
   


    
}