#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 3010
#define inf 0x3f3f3f3f
int n;
char grid[MAX][MAX]; 
bool vis[MAX][MAX] = {}; 
vector<pair<int, int>> mov = {{1, 0}, {0, 1}}; 

bool val(const pair<int, int> &p){
    if(p.first < n && p.second < n) return true; 
    return false; 
}

int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> grid[i][j]; 
    }

    vector<pair<int, int>> curr = {{0, 0}}; //contem os niveis atuais de caracteres que são potencialmente otimas para a solucao final 
    //como eu so posso andar para direita ou para esquerda, 
    //num grid n * n, eu posso ter uma resposta de no maximo 2 * n - 1; como a primeira
    //resposta ja começa no vetor, ent, so preciso ir ate 2 * n - 2
    string ans; ans += grid[0][0];
    for(int i = 0; i < 2 * n - 2; i++){
        char best = 'Z';
        for(auto k: curr){
            for(auto m: mov){
                m.first += k.first, m.second += k.second; 
                if(val(m))
                    best = min(best, grid[m.first][m.second]);
            }
        }

        vector<pair<int, int>> next_curr; 

        for(auto k: curr){            
            for(auto m: mov){
                m.first += k.first, m.second += k.second;
                if(val(m) && !vis[m.first][m.second]){
                    if(grid[m.first][m.second] == best){
                        next_curr.push_back(m); 
                        vis[m.first][m.second] = 1; 
                    }                    
                }
            }
        }

        curr = move(next_curr); 
        ans += best; 
    }

    cout << ans << endl; 
    
    
}