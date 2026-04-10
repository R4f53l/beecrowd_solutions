#include <bits/stdc++.h> 

using namespace std; 

typedef struct basket{
    int p, cf, ct, ni;   
    basket(): p(0), cf(0), ct(0){}
}basket;

bool comp (const basket &a, const basket &b){
    if(a.p == b.p){
        double ca = a.ct ? (double) a.cf/a.ct : (double) a.cf, cb = b.ct ? (double) b.cf/b.ct : (double) b.cf;
        if(ca == cb){
            if(a.cf == b.cf)
                return a.ni < b.ni; 
            
            else return a.cf > b.cf; 
        }
        else return ca > cb; 
    }
    else return a.p > b.p; 
}

int main (){
    int n, c = 1, first = 1; 
    while(cin >> n, n){
        vector<basket> v(n);
        if(first) first = 0; 
        else cout << endl; 
        for(int i = 0; i<(n *(n-1))/2; i++){
            int x, y, z, w; cin >> x >> y >> z >> w; 
            v[x-1].cf += y, v[x-1].ct += w, v[z-1].cf += w, v[z-1].ct += y, v[x-1].ni = x; v[z-1].ni = z;   
            if(y > w) {
                v[x-1].p += 2; 
                v[z-1].p += 1; 
            }
            else {
                v[z-1].p += 2; 
                v[x-1].p += 1; 
            }
                      
        }
        sort(v.begin(), v.end(), comp);
        cout << "Instancia " << c++ << endl; 
        for(int i = 0; i<n-1; i++)
            cout << v[i].ni << " ";                   
        cout << v[n-1].ni << endl;   
        
        
    }
}