#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define inf 0x3f3f3f3f
#define MAX 1000010


vector<pair<int, int>> seg(4 * MAX); 
vector<int> lazy (4 * MAX, 0); 
vector<int> v(MAX);

pair<int, int> max_n(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first)
        return a; 
    else if(b.first > a.first)
        return b; 
    else 
        return min(a, b); 
}

void push (int p){
    if(!lazy[p]) return; 
    seg[2 * p].first += lazy[p]; 
    seg[2 * p + 1].first += lazy[p]; 
    lazy[2 * p] += lazy[p]; 
    lazy[2 * p + 1] += lazy[p]; 
    lazy[p] = 0; 
}

void build (int p, int l, int r){    
    if(l == r){
        seg[p] = {v[l], l}; 
        return; 
    }
    int m = (l + r)/ 2;
    build(2 * p, l, m); 
    build(2 * p + 1, m + 1, r); 
    seg[p] = max_n(seg[2 * p], seg[2 * p + 1]);     
}

pair<int, int> query(int p, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return {-inf, -1};  

    if(l >= ql && r <= qr)
        return seg[p]; 
    
    push(p); 

    int m = (l + r)/ 2;
    return max_n(query(2 * p, l, m, ql, qr), query(2 * p + 1, m + 1, r, ql, qr)); 
}

void update(int p, int valor, int l, int r, int ql, int qr){
    
    if(l > qr || r < ql) return; 

    if(l >= ql && r <= qr){
        seg[p].first += valor; 
        lazy[p] += valor; 
        return; 
    }
    push(p); 
    int m = (l + r)/2; 
    update(2 * p, valor, l, m, ql, qr); 
    update(2 * p + 1, valor, m + 1, r, ql, qr); 
    seg[p] = max_n(seg[2 * p], seg[2 * p + 1]); 
}


int main(){_
    int n, q; 
    
    while(cin >> n >> q){
        fill(lazy.begin(), lazy.begin() + 4 * n, 0);        
        
        for(int i = 0; i < n; i++) cin >> v[i];     
        
        build(1, 0, n - 1); 

        
        while(q--){
            char c; int a, b; cin >>  c >> a >> b; 
            if(c == 'C')
                cout << query(1, 0, n - 1, a - 1, b - 1).second + 1 << endl; 
            else{
                int valor; cin >> valor; 
                update(1, valor, 0, n - 1, a - 1, b - 1); 
            }
        }
    }
}