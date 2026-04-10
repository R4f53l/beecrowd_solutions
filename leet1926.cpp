class Solution {
public:    
    int dist[101][101] = {}, vis[101][101] = {};
    vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
    bool eh_val(pair<int, int> p, vector<vector<char>>& maze){
        return p.first >= 0 && p.second >= 0 && p.first < maze.size() && p.second < maze[0].size() && !vis[p.first][p.second] && maze[p.first][p.second] == '.'; 
    }
    int bfs (vector<int> &entrance, vector<vector<char>>& maze){
        queue<pair<int, int>> q; q.push({entrance[0], entrance[1]}); 
        dist[entrance[0]][entrance[1]] = 0; 

        while(!q.empty()){
            pair<int, int> v = q.front(); q.pop(); 
            if(dist[v.first][v.second] && (v.first == 0 || v.first == maze.size() - 1 || v.second == 0 || v.second == maze[0].size() - 1))
                return dist[v.first][v.second]; 
            for(auto k: mov){
                k.first += v.first, k.second += v.second; 
                if(eh_val(k, maze)){
                    q.push(k);
                    dist[k.first][k.second] = dist[v.first][v.second] + 1;
                    vis[k.first][k.second] = 1;   
                }
            }
        }
        return -1; 
        
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return bfs(entrance, maze);
    }
};