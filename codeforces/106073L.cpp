#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

const long long inf = 1e18; 

int main(){_ 

    map<string, pair<int, int>> m; 
    vector<string> entrada; 
    int n; cin >> n; 

    for(int i = 0; i < n; i++){
        string s; 
        int x, y; cin >> s >> x >> y; 
        entrada.push_back(s);
        m[s] = {x, y}; 
    }

    int fraselenght; cin >> fraselenght; 
    vector<string> frase(fraselenght);
    
    for(int i = 0; i < fraselenght; i++){
        cin >> frase[i]; 
        if(m.count(frase[i])) continue; 
        m[frase[i]] = {0, 0}; 
    }        
     

    int q, k; cin >> q >> k;
    
    for(int h = 0; h < q; h++){        
        vector<string> v; 
        int f; cin >> f; 

        for(int i = 0; i < f; i++){
            string s; cin >> s; 
            v.push_back(s); 
        }
    
        vector<string> candidates; 

        for(int z = k; z > 0; z--){
            for(int i = 0; i + z < fraselenght; i++){
                bool ok = true; 
                
                for(int j = 0; j < z; j++){
                    if(frase[i + j] != v[f - z + j]){
                        ok = false; break; 
                    }
                }
                if(ok)
                    candidates.push_back(frase[i + z]);               
            }
            if(!candidates.empty()) break; 
        }

        //em ambos os casos eu imprimo a frase...

        for(int i = 0; i < f; i++)
            cout << v[i] << " ";          
        

        //se candidates n tiver nada, então, não temos candidatos e a resposta eh *
        //se tiver, iremos pegar o maior produto interno, tendo em vista que em caso de empate, pegamos na ordem de entrada
        //como o map ordena, então, precisaremos salvar a entrada

        if(candidates.empty()){
            cout << "*" << endl;
            continue; 
        }                       

        long long ans = -inf; 
        string anss; 
        for(auto s: entrada){
            long long score = 0; 
            for(auto c: candidates){                
                score +=  ((long long) m[c].first * m[s].first + (long long) m[c].second * m[s].second);                 
            }
            if(score > ans){
                ans = score; 
                anss = s; 
            }
        }

        cout << anss << endl; 


    }

}