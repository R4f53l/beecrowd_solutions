#include <bits/stdc++.h> 

using namespace std; 

int comp (const pair<string, int>&a, const pair<string,int>&b) {
    if(!(a.first.size() - b.first.size()))
        return a.second < b.second; 
    return a.first.size() < b.first.size(); 
}

int main () {
    int n, t = 0; 
    vector<pair<string, int>> v; 
    vector<string> names; 
    cin >> n; 

    for(int i = 0; i < n; i++){
        string s; 
        cin >> s; 
        v.push_back(make_pair(s, i));
    }

    sort(v.begin(), v.end(), comp);    
    
    
    int i = 0;
    while (!v.empty()) {

        if(v[i].first.size() > t){
            names.push_back(v[i].first);
            t = v[i].first.size();
            v.erase(v.begin() + i);
        } 

        else 
            i++;        

        
        if (i == v.size()){
            i = 0;
            t = 0; 
        }
    }
    
    

    for(int i = 0; i<names.size()-1; i++){
        if(names[i].size() < names[i+1].size())
            cout << names[i] << ", ";
        else cout << names[i] << "\n";
    }
    cout << names[names.size()-1] << "\n";
    
}