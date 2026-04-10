#include <bits/stdc++.h> 

using namespace std; 

vector <int> v; 
void backtrack (int n){
    if(n == 3){
        for(auto i: v)
            cout << i; 
        return; 
    }
    v.push_back(n); 
    backtrack(n + 1); 
    v.pop_back(); 
    backtrack(n + 1); 
}

int main (){
    backtrack(0); 

}