#include <bits/stdc++.h> 

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 1000

vector<pair<int, int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 

char grid[MAX][MAX]; 
int m, n;
int dist [MAX][MAX] = {}; 
vector<char> ans;
bool val (pair<int, int> k){
    return k.first >= 0 && k.second >= 0 && k.first < m && k.second < n && dist[k.first][k.second] == -1 &&
    (grid[k.first][k.second] == '.' || grid[k.first][k.second] == 'B');
    
}



void bfs (pair<int, int> start){
    queue <pair<int, int>> q; 
    q.push(start); 
    dist[start.first][start.second] = 0;

    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop(); 
        
        if(grid[v.first][v.second] == 'B') return; 
        //00 -> 10
        for(auto k: mov){            
            pair<int, int> newmov; 
            newmov.first = (v.first + k.first); newmov.second = (v.second + k.second);              
            if(val(newmov)){           
                                
                q.push(newmov);
                dist[newmov.first][newmov.second] = dist[v.first][v.second] + 1; 
                
            }
        }
    }

}

int main(){
    cin >> m >> n; 
    pair<int, int> start, end;  

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];             
            if(grid[i][j] == 'A')
                start = {i, j}; 
            if(grid[i][j] == 'B')
                end = {i, j};     
            
        }
    }
    
    memset(dist, -1, sizeof(dist)); 
    bfs(start); 
    
    int i = end.first, j = end.second, cont = 0; 
    
    bool nopath = 0; 
    while(grid[i][j] != 'A'){    
        int menor = dist[i][j];           
        pair<int, int> movi;        
        cont = 0;
        for(auto k: mov){            

            k.first += i, k.second += j;             
            if(k.first < 0 || k.second < 0 || k.first >= m || k.second >= n){
                cont++;
                continue;    
            }         
            else if (dist[k.first][k.second] == -1){
                cont++; continue; 
            }
            if(dist[k.first][k.second] < menor){                
                menor = dist[k.first][k.second];
                movi = {k.first, k.second};                 
            }           
        }               
        if(cont == 4){
            nopath = 1; break;
        }
        if((movi.first - i) * -1 == 1) ans.push_back('D'); 
        else if((movi.first - i) * -1 == -1) ans.push_back('U'); 
        else if ((movi.second - j) * -1== 1) ans.push_back('R'); 
        else ans.push_back('L'); 
        i = movi.first, j = movi.second;
    }

    if(nopath) cout << "NO"<< endl; 
    else {
        cout << "YES" << endl;
        cout << dist[end.first][end.second] << endl;
        for(int i = ans.size() - 1; i>=0; i--)
            cout << ans[i];  
    }
}