#include <bits/stdc++.h> 

using namespace std; 

int main (){
    int t; cin >> t; 
    while(t--){
        int m, n; cin >> m >> n; 
        cin.ignore();
        map<string, string> dic; 
        for(int i = 0; i<m; i++){
            string j, p; getline(cin, j); getline(cin, p);
            dic[j] = p; 
        }
        for(int i = 0; i<n; i++){
            string s, palavra; getline(cin, s);
            stringstream ss(s);
            while(ss >> palavra){
                auto search = dic.find(palavra);
                if(search != dic.end())
                    cout << dic[palavra];  
                else cout << palavra; 
                if(ss.peek() != EOF) cout << " "; 
            }
            cout << endl; 
        }
        cout << endl; 
    }
}