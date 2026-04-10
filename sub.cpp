#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

//codigo para gerar todos os subconjuntos com backtrack

int n = 3; 
vector<int> v; 

void backtrack (int c){
    if (c == 3){
        for(auto k: v)
            cout << k << " "; 
        cout << endl; 
        return;
    }

    v.push_back(c); 
    backtrack(c + 1);
    v.pop_back(); 
    backtrack(c + 1);     
}

int main (){_
    backtrack(0);     
}