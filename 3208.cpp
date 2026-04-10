#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 1e6 + 10; 

int t = 2; 
vector<int> n_primos; 
vector<bool> primos (MAX, true);

int verifica (const string &a, int j){
    int r = 0, i = 0;
    for(auto c: a){
        r = ((r * 10) + (c - '0')) % j; //1 10 + 4 14 % 7 = 0 
        i++;
    }
    return r; 
}

void crivo () {
    for (int i = 2; i * i <= MAX; i++){
        if(primos[i]){
            for(int j = i * i; j<=MAX; j+=i)
                primos[j] = false; 
        }
    }
    
    int i; 
    
    for(i = t; i<primos.size(); i++)
        if(primos[i]) n_primos.push_back(i);  
    
}


int main(){
    int j; 
    string s; 
    crivo();
    while(cin >> s >> j, j){ 
        int ans = -1; 
        
        for(auto i: n_primos){    
            if(i >= j) break;    
            if(!verifica(s, i)){
                ans = i; 
                break;
            }
        }
    
        if(ans != -1) cout << "BAD " << ans << endl; 
        else cout << "GOOD" << endl;         
    }
    return 0;
}