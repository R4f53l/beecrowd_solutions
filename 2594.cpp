#include <bits/stdc++.h> 

using namespace std; 

int main (){
    int n; cin >> n; 
    while(n--){
        cin.ignore();
        string s, search; 
        getline(cin, s); cin >> search; 
        
        unordered_map<string, vector<int>> v; 
        stringstream ss(s);
        string palavra; 
        int i = 0; 
        while(ss >> palavra){            
            v[palavra].push_back(i); 
            i += palavra.size() + 1;
        }

        vector<int> ans; 

        for(auto[palavra, indice]: v){            
            if(palavra == search){
                for(int i: indice)
                    ans.push_back(i);
            }
        }
        
        if(!ans.size()) cout << "-1";
        else{
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i]; 
                if(i < ans.size() - 1) cout << " ";             
            }
        }

        cout << endl; 
        
    }
}