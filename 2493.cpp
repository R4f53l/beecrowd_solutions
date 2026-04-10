#include <bits/stdc++.h> 

using namespace std; 

typedef struct jogo{
    int a, s, m, i; 
    jogo(): a(0), s(0), m(0), i(0) {}
}jogo; 

int main (){
    int n; 
    while(~scanf("%d", &n)){
        vector<jogo> p(n);
        for(int i = 0; i<n; i++){
            int a, b, c, t = 0; scanf("%d %d=%d", &a, &b, &c);
            if(a + b == c){
                p[i].a = 1, t = 1; 
            }
            if(a - b == c){
                p[i].s = 1; t = 1; 
            }
            if(a * b == c){
                p[i].m = 1; t = 1; 
            }
            if(!t) p[i].i = 1; 
        }
        vector<string> v; 
        for(int i = 0; i<n; i++){
            string s; int d; char c; 
            cin >> s >> d >> c; 
            if(p[d-1].i && c != 'I') v.push_back(s);
            else if((c == 'I' && !p[d-1].i) || (c == '+' && !p[d-1].a) || (c == '*' && !p[d-1].m) || (c == '-' && !p[d-1].s))
                v.push_back(s);
        }
        if(v.size() == n) printf("None Shall Pass!\n");
        else if(v.size() == 0) printf("You Shall All Pass!\n");
        else{
            sort(v.begin(), v.end());
            for(int i = 0; i<v.size()-1; i++)
                cout << v[i] << " "; 
            cout << v[v.size()-1] << endl;  
        }
    }
}