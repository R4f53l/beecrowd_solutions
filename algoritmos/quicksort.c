int ordena (const void *a, const void *b){
    if(*(int*)a == *(int*)b) //sao iguais; 
        return 0; 
    else if (*(int*)a < *(int*) b) 
        return -1; //vem depois
    else    
        return 1; //vem antes
}

/*
ao chamar a funcao: 
qsort (vetor, tamanho, sizeof(tipo), ordena);

*/