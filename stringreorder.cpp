#include <bits/stdc++.h> 
using namespace std; 

#define MAX 26
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

bool f = 0; 
int k = 0; 
vector<int> vis(MAX, 0); 

void resolve (string &solution, int qnt, char c){

    vis[c - 'A'] = 1; 

    for(int i = 0, ind = k; i < qnt && ind < solution.size(); i++, ind += 2)
        solution[ind] = c; 

    while(k < solution.size() && solution[k] != ' ') k++;  
}

int main (){_
    string s; cin >> s; 
    map<char, int> v;    

    for(int i = 0; i < s.size(); i++)
        v[s[i]]++; 
    
    string solution (s.size(), ' ');    
    
    for(auto[c, qnt]: v){
        if(vis[c - 'A']) continue; 
        if(qnt - 1 > s.size() / 2) f = 1; 

        for(auto[c1, qntd1]: v){
            if(vis[c1 - 'A']) continue; 
            if(k >= solution.size()) break;

            

            if (qntd1 + 2*k >= s.size()) 
                resolve(solution, qntd1, c1);
        }

        if(k < solution.size())
            resolve(solution, qnt, c);
    }

    if(!f) cout << solution << endl; 
    else cout << "-1" << endl;
}