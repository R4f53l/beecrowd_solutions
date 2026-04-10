#include <bits/stdc++.h> 

using namespace std; 

#define MAX 100

bitset<9> column, dig1, dig2; 
int n, cont = 0;
vector<string> v; 
vector<vector<string>> vv;
void backtrack (int c, int l){
    if(c == n){
        cont++;              
        for(int i = 0; i < c; i++){
            string t; 
            for(int j = 0; j < c; j++){          
                if(column[j]) t += 'Q';
                else t += '.';
            }
            v.push_back(t);
        }
        vv.push_back(v);
    }

    for(int i = 0; i < n; i++){
        if(column[i] || dig1[l - i + n - 1] || dig2[l + i]) continue;
        column[i] = dig1[l - i + n - 1] = dig2[l + i] = 1; 
        backtrack(i + 1, l + 1); 
        column[i] = dig1[l - i + n - 1] = dig2[l + 1] = 0;
    }
}

int main (){
    cin >> n; 
    backtrack(0, 0);

    cout << cont << endl;
    
    for(auto k: vv){
        for(auto t: k) cout << t; 
        cout << endl;
    }
    
}