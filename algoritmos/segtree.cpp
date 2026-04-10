#include <bits/stdc++.h> 

using namespace std; 
const int MAX = 1e5 + 1; 

#define inf 0x3f3f3f3f

int v[MAX]; 
int seg[4*MAX]; 
int lazy[4*MAX]; 

void propagate(int p, int l, int r){
    if(lazy[p] != inf){
        seg[p] = min(lazy[p], seg[p]); 
        if(l != r){
            lazy[2*p] = min (lazy[p], lazy[2*p]); 
            lazy[2*p+1] = min (lazy[2*p+1], lazy[p]); 
        }
        lazy[p] = inf; 
    }    
}

int build (int p, int l, int r){
    if(l == r) return seg[p] = v[l]; 
    int m = (l+r)/2; 
    return seg[p] = min (build(2*p, l, m), build(2*p+1, m+1, r)); 
}

int query (int a, int b, int p, int l, int r){
    propagate(p, l, r);
    if(a > r || l > b) return inf; 
    if(a <= l && r <= b) return seg[p]; 
    int m = (l+r)/2; 
    return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

int update (int a, int b, int x, int p, int l, int r){
    propagate(p, l, r);
    if(a > r || l > b) return seg[p]; 
    if(a <= l && r <= b){
        lazy[p] = x; 
        propagate(p, l, r); 
        return seg[p]; 
    }
    int m = (l+r)/2; 
    return seg[p] = min(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r)); 
}   

int main (){
    v[0] = 3, v[1] = 8, v[2] = 7, v[3] = 2; 
    build(1, 0, 3); 
    memset(lazy, inf, sizeof lazy); 
    cout << query(0, 1, 1, 0, 3) << endl;     
    update(0, 1, -1, 1, 0, 3); 
    cout << query(0, 3, 1, 0, 3) << endl;
}