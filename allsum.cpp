#include <bits/stdc++.h> 

using namespace std; 

vector <int> ans, v; 
void backtrack(int current_sum, int target, int n){
    if(current_sum == target){
        for(auto i: ans)
            cout << i << " ";      
        cout << endl;
        return;
    }

    for(int i = n; i < v.size(); i++){
        if(current_sum + v[i] > target) continue; 
        ans.push_back(v[i]); 
        backtrack(current_sum + v[i], target, i + 1); 
        ans.pop_back(); 
    }
}

int main (){
    int n, s; 
    cin >> n >> s; 
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.push_back(a); 
    }

    sort(v.begin(), v.end()); 

    backtrack(0, s, 0); 
}