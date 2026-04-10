#include <bits/stdc++.h> 

using namespace std; 


int main (){
    int n; cin >> n; 
    vector<int> v(n); 
    for(auto &i: v) cin >> i; 
    deque<int> d; 
    for(int i = 0; i < v.size(); i++)
        d.push_back(v[i]); 
    sort(d.begin(), d.end(), greater<int>());

    int qnts = 0, id = 0, rounds = 0;
    while(qnts < d.size()){ //(d.size() + v.size()) * v[i]
        rounds++;
        for(int i = 0; i < v.size(); i++){
            if(v[i] != d[id]){
                qnts += d[i] - v[i] + 1;//quantos elementos eu removi;
                id += (d[i] - v[i] + 1);
            }            
        }
    }
    cout << rounds << endl;
}