#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

const int MAX = 11; 

int grid[MAX][MAX] = {}; 

int main(){_ 
    int n, f = 0; cin >> n; 
    for(int i = 0; i < n; i++){
        int d, l, r, c; cin >> d >> l >> r >> c;          
        if(!d){
            if(c + l - 1 > 10) f = 1; 
            else{
                for(int i = c; i <= c + l - 1; i++){
                    if(!grid[r][i]) grid[r][i] = 1; 
                    else f = 1; 
                }
            }
        }
        else{
            if(r + l - 1 > 10) f = 1; 
            else{
                for(int i = r; i <= r + l - 1; i++)
                if(!grid[i][c]) grid[r][i] = 1; 
                else f = 1; 
            }
        }
    }

    if(!f) cout << "Y" << endl; 
    else cout << "N" << endl;

}