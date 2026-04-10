#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);

void pos_ordem (string a, string b){
    if(a.size() < 1) return;    
    int i = a.find(b[0]);
    pos_ordem(a.substr(1, i), b.substr(0, i - 1));
    pos_ordem(a.substr(1 + i, a.size() - i + 1), b.substr(i + 1, b.size() - i)); 
    cout << a[0] << endl;
}

int main (){

}