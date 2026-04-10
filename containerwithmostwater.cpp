#include <bits/stdc++.h> 

using namespace std; 

#define inf 0x3f3f3f3f

int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};    
    vector<int> area(height.size(), -inf);
    //problema da abordagem: o(n^2); usar two pointers
    // 1 2 3 4 5 6 7 8
    for(int i = 1; i < height.size(); i++){
        for(int j = i - 1; j >= 0; j--){
            area[i] = max(min(height[i], height[j]) * (i - j), area[i]); 
        }
    }

    for(int i = 0; i < area.size(); i++){
        cout << area[i] << " "; 
    }
    
}