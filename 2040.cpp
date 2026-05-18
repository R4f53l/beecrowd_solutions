#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 101

int main(){
    int n; 
    while(scanf("%d", &n), n){
        map<string, int> m; 
        for(int i = 0; i < n; i++){
            int p; char s[MAX];             
            scanf("%s %d", s, &p);              
            m[(string)s] = p;            
        }      

        for(int i = 0; i < n / 2; i++){
            char s1[MAX], s2[MAX]; int g1, g2; 
            scanf("%s %d-%d %s", s1, &g1, &g2, s2);             
            if(g1 > g2){
                m[(string) s1] += (g1 * 3) + 5; 
                m[(string) s2] += g2 * 3; 
            }
            else if(g1 < g2){
                m[(string) s2] += (g2 * 3) + 5; 
                m[(string) s1] += g1 * 3;
            }
            else {
                m[(string) s1] += (g1 * 3) + 1; 
                m[(string) s2] += (g2 * 3) + 1; 
            }
        }

        int pontos = -1; 
        string ans; 
        for(auto[s, p]: m){            
            if(pontos < p){
                ans = (string) s; 
                pontos = p; 
            }
        }
        if(m["Sport"] < pontos){
            printf("O Sport nao foi o campeao. O time campeao foi o "); 
            for(int i = 0; i < ans.size(); i++)
                printf("%c", ans[i]); 
            printf(" com %d pontos :(\n", pontos);
        }
        else printf("O Sport foi o campeao com %d pontos :D\n", m["Sport"]);

        cout << endl;
    }
}