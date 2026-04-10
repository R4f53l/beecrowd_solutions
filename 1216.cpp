#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    int a, c = 0, soma = 0;
    setbuf(stdin, NULL);
    while(1){
        if(getline(cin, s)){
            if(scanf("%d", &a)!=EOF){
                c++;
                soma+=a; 
            }
        }
        else break;        

    }
    printf("%.1lf",(double)soma/3.0);
    
    return 0;
}