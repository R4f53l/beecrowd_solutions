#include <bits/stdc++.h> 

using namespace std; 

vector<pair<int, int>> mov = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
const int MAX = 8;
bool val (pair<int, int> p, pair<int, int> k){
    return p.first >= 0 && p.first < MAX && p.second >= 0 && p.second < MAX &&
    p.first == k.first && k.second == p.second; 
}

int main (){
    string a, b; 
    cin >> a >> b; 
    pair<int, int> p = {a[1] - '1', a[0] - 'a'}, k = {b[1] - '1', b[0] - 'a'};
    
    int c = 0;
    for(auto q: mov){
        q.first += p.first, q.second += p.second; 
        if(val(q, k)){c = 1; break;}
    }

    if(c) cout << "VALIDO" << endl; 
    else cout << "INVALIDO" << endl; 
}