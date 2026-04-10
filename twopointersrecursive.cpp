#include <bits/stdc++.h> 

using namespace std; 
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

vector<int> v = {1, 3, 2, 5, 1, 1, 2, 3};
int target = 8; 

pair<int, int> sub (int i, int f, int soma){    
    if(i > f && f < v.size())
        return sub(i, f + 1, soma); 
    if(soma == target)
        return {i, f-1};  
    if(soma > target && i <= f)
        return sub(i + 1, f, soma - v[i]);
    if(f < v.size())
        return sub(i, f + 1, soma + v[f]); 
    return {-1, -1}; 
}

int main (){_

    pair<int, int> ans = sub(0, 0, 0);
    cout << ans.first << " " << ans.second << endl;  

}