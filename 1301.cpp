#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 100010

int seg[4 * MAX];

int inserir (int valor){
    if(valor > 0) return 1; 
    else if(valor < 0) return -1; 
    return 0; 
}


void build (int p, int l, int r, int *v){
    if(l == r){
        int valor = inserir(v[l]); 
        seg[p] = valor; 
        return; 
    }
    int m = (l + r)/2; 
    build (2 * p, l, m, v); 
    build (2 * p + 1, m + 1, r, v); 
    seg[p] = seg[2 * p] * seg[2 * p + 1]; 
}

int query (int p, int l, int r, int ql, int qr){    
    if(ql > r || l > qr) return 1; 
    if(l >= ql && r <= qr)
        return seg[p]; 
    int m = (l + r)/2; 

    return query(2 * p, l, m, ql, qr) * query(2 * p + 1, m + 1, r, ql, qr);

    
}

void update (int p, int l, int r, int idx, int valor){    
    if(idx > r || l > idx) return; 
    else if(l == r){
        int t = inserir(valor); 
        seg[p] =  t; 
        return; 
    }

    int m = (l + r)/2;
    update(2 * p, l, m, idx, valor); 
    update(2 * p + 1, m + 1, r, idx, valor); 
    seg[p] = seg[2 * p] * seg[2 * p + 1];
}

int main(){_
    int n, k; 
    while(cin >> n >> k){
        int v[n]; 
        string ans; 
        for(auto &i: v) cin >> i; 

        build(1, 0, n-1, v); 

        for(int i = 0; i < k; i++){
            char c; int a, b; cin >> c >> a >> b; 
            a--;
            if(c == 'C') update(1, 0, n-1, a, b);
            else{
                b--; 
                int result = query (1, 0, n-1, a, b);                 
                if(result > 0) ans.push_back('+'); 
                else if(result < 0) ans.push_back('-'); 
                else ans.push_back('0'); 
            }  
                    
        }

        cout << ans << endl;        
        
    }
    
}