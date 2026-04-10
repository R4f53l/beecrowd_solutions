#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL); 

const int MAX = 1e3 + 1; 

typedef struct quadro {    
    int o, b, p; 
    quadro(): o(0), b(0), p(0) {}
}quadro; 

int comp (const pair<string, quadro> &a, pair<string, quadro> &b){
    if(a.second.o == b.second.o){
        if(a.second.p == b.second.p)
            if(a.second.b == b.second.b)
                return a.first < b.first; 
            else return a.second.b > b.second.b; 
        else return a.second.p > b.second.p; 
    }
    else return a.second.o > b.second.o; 
}

int main (){_
    int i = 0;
    map<string, quadro> m; 
    string e, p1, p2, p3;
    while(getline(cin, e)){        
        getline(cin, p1); getline(cin, p2); getline(cin, p3);
        m[p1].o++; m[p2].p++; m[p3].b++;         
    }
    vector<pair<string, quadro>> v;
    for(auto &entry: m)
        v.push_back(entry); 
    sort(v.begin(), v.end(), comp);
    cout << "Quadro de Medalhas" << endl;
    for(auto k: v)
        cout << k.first << " " << k.second.o << " " << k.second.p << " " << k.second.b << endl; 
    
    


}