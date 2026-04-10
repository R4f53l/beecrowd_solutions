#include <bits/stdc++.h> 

using namespace std; 
int n = 3; 
vector<int> ans; 
vector<bool> chosen (n, false); 
void backtrack (){
    if(ans.size() == n){
        for(auto i: ans)
            cout << i; 
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        if(chosen[i]) continue; 
        chosen[i] = true; 
        ans.push_back(i); //012, 01, 021  
        backtrack(); 
        chosen[i] = false; 
        ans.pop_back(); 
    }

    //012, 021, 201, 210, 120, 102
}

int main (){
    
    backtrack(); 

}