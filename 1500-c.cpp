#include <bits/stdc++.h> 
using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL); 

const int MAX = 1e5 + 10; 

long long lazy[4 * MAX]; 
long long seg[4 * MAX];

void propagate(int p, int l, int r) {
    if (lazy[p] != 0) {  
        seg[p] += (r - l + 1) * lazy[p];  

        if (l != r) {  
            lazy[2 * p] += lazy[p]; 
            lazy[2 * p + 1] += lazy[p]; 
        }

        lazy[p] = 0;  
    }
}

long long query(int a, int b, int p, int l, int r) {
    propagate(p, l, r);
    
    if (l > b || r < a) return 0; 
    if (a <= l && r <= b) return seg[p];  

    int m = (l + r) / 2;
    return query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r);
}

long long update(int a, int b, int x, int p, int l, int r) {
    propagate(p, l, r);  // Propaga antes de modificar

    if (l > b || r < a) return seg[p]; 
    if (a <= l && r <= b) {  
        lazy[p] += x;  // Marca para propagar depois
        propagate(p, l, r);  // Aplica imediatamente
        return seg[p];
    }

    int m = (l + r) / 2;

    return seg[p] = update(a, b, x, 2 * p, l, m) + update(a, b, x, 2 * p + 1, m + 1, r);
}

int main() {_
    int t; cin >> t; 
    while (t--) {
        int n, c; cin >> n >> c;  
        memset(lazy, 0, sizeof lazy);
        memset(seg, 0, sizeof seg);

        for (int i = 0; i < c; i++) {
            int b, p, q; cin >> b >> p >> q;  
            p--, q--;  

            if (!b) {
                int v; cin >> v;  
                update(p, q, v, 1, 0, n - 1);  
            } else {
                cout << query(p, q, 1, 0, n - 1) << endl;  
            }
        }
    }
}
