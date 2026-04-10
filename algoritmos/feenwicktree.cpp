#include <bits/stdc++.h> 

using namespace std; 

int v [] = {1, -1, 3, 7, 8, 10}; 
int BIT [7] = {}; 

int query (int idx){
    int s = 0; 
    while(idx > 0){
        s += BIT[idx]; 
        idx -= (idx & -idx); 
    }
    return s; 
}

void update (int idx, int val){
    int n = 6; 
    while(idx <= n){
        BIT[idx] += val; 
        idx += (idx & -idx); 
    }
}

void constroi (){
    for(int i = 1; i<=6; i++)
        update(i, v[i-1]); 
}

int main (){
    constroi(); 
    cout << query (4) << endl; 
    cout << BIT[4] << endl; 
    
}