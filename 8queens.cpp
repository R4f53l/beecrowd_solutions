#include <bits/stdc++.h> 

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 8

vector<int> row(MAX); 

bool eh_possivel (int c, int l){
    for(int i = 0; i < c; i++){
        if(row[i] == l || abs(row[i] - l) == abs (c - i)) return false; 
    }
    return true; 
}

void backtrack (int c){
    if(c == MAX){
        for(auto k: row)
            cout << k + 1 << " "; 
        cout << endl; 
        return; 
    }

    for(int i = 0; i < MAX; i++){
        if(eh_possivel(c, i)){
            row[c] = i, backtrack(c + 1); 
        }
    }



}

int main (){_
    backtrack(0); 
}