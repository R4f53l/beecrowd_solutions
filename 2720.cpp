#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        vector<pair<int, int>> gifts(n); 
        for(int i = 0; i < n; i++){
            int id, h, w, l; cin >> id >> h >> w >> l; 
            gifts[i] = {id, h * w * l}; 
        }

        sort(gifts.begin(), gifts.end(), [](pair<int, int> &a, pair<int, int> &b){
            if(a.second == b.second)
                return a.first < b.first; 
            else return a.second > b.second; 
        });

        vector<int> ans; 

        for(int i = 0; i < k; i++){
            ans.push_back(gifts[i].first); 
        }            

        sort(ans.begin(), ans.end());

        for(int i = 0; i < ans.size(); i++){
            cout << ans[i]; 
            if(i < ans.size() - 1) cout << " "; 
        }
        cout << endl; 

    }
}