#include <stdio.h> 
int main () {
    int d, m; 
    scanf("%d/%d", &d, &m);
    if(m==1){
        if(d<=19)
            printf("capricornio\n");
        else 
            printf("aquario\n");
    }
    if(m==2){
        if(d<=18)
            printf("aquario\n");
        else 
            printf("peixes\n");
    }
    if(m==3){
        if(d<=20)
            printf("peixes\n");
        else 
            printf("aries\n");
    }
    if(m==4){
        if(d<=20)
            printf("aries\n");
        else 
            printf("touro\n");
    }
    if(m==5){
        if(d<=20)
            printf("touro\n");
        else 
            printf("gemeos\n");
    }
    if(m==6){
        if(d<=20)
            printf("gemeos\n");
        else 
            printf("cancer\n");
    }
    if(m==7){
        if(d<=22)
            printf("cancer\n");
        else 
            printf("leao\n");
    }
    if(m==8){
        if(d<=22)
            printf("leao\n");
        else 
            printf("virgem\n");
    }
    if(m==9){
        if(d<=22)
            printf("virgem\n");
        else 
            printf("libra\n");
    }
    if(m==10){
        if(d<=22)
            printf("libra\n");
        else 
            printf("escorpiao\n");
    }
    if(m==11){
        if(d<=21)
            printf("escorpiao\n");
        else 
            printf("sagitario\n");
    }
    if(m==12){
        if(d<=19)
            printf("sagitario\n");
        else 
            printf("capricornio\n");
    }








    return 0;
}