#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main (){_ 
    int n;

    while(cin >> n){
        int semelhanca = 0;
        vector<string> v(n);
        for(auto &k: v) cin >> k; 
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++){
            string s1 = v[i - 1], s2 = v[i];
            for(int i = 0; i < s1.size(); i++){
                if(s1[i] == s2[i]) semelhanca++; 
                else break;
            }
        }
        cout << semelhanca << endl;
    }

}