#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 110; 
int l, c, p = 0; 
char M[MAX][MAX]; 
bool vis[MAX][MAX];
vector<pair<int, int>> mov = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool val (pair<int, int> p){
    return p.first >= 0 && p.second >= 0 &&
        p.first < l && p.second < c && 
        (M[p.first][p.second] == '.' || M[p.first][p.second] == '*') &&
        !vis[p.first][p.second];
}

void bfs (pair<int, int> s, int t){
    queue<pair<int, int>> q; q.push(s);
    vis[s.first][s.second] = 1; 
    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop();
        pair<int, int> k; 
        k.first = v.first + mov[t].first; k.second = v.second + mov[t].second; 
        if(val(k)){
            if(M[k.first][k.second] == '*') p = 1;
            q.push(k);
            vis[k.first][k.second] = 1; 
        }
        
    }
}

int main (){
    cin >> c >> l; 
    
    for(int i = 0; i<l; i++){
        for(int j = 0; j<c; j++)
            cin >> M[i][j];
    }
    
    
    for(int i = 0; i<l; i++){
        for(int j = 0; j<c; j++){
            if(vis[i][j]) break;
            
            if((M[i][j] == '>' || M[i][j] == '<' || M[i][j] == '^' || M[i][j] == 'v') && !vis[i][j]){
                int t;
                if(M[i][j] == '>') t = 0; else if(M[i][j] == '<') t = 1; 
                else if (M[i][j] == '^') t = 2; else t = 3; 
                bfs({i, j}, t);
            }
            
        }
    }
    printf("%c\n", p ? '*' : '!');
    
}