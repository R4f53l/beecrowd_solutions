#include <bits/stdc++.h> 
using namespace std;
struct pais {
    string s; 
    int o, p, b; 
};
bool comp (const pais &a, const pais &b){
    if(a.o!=b.o)
        return a.o>b.o;
    if(a.p!=b.p)
        return a.p>b.p; 
    if(a.b!=b.b)
        return a.b>b.b;
        
        return a.s < b.s;
}
int main () {    
    int n; 
    cin >> n;
    vector<pais> v(n); 
    for(auto &p: v){
        cin >> p.s >> p.o >> p.p >> p.b;
    }
    sort(v.begin(), v.end(), comp);
    for(auto &p: v){
        cout << p.s << " " << p.o << " " << p.p << " " << p.b << endl;
    }
    
        




    return 0;
}