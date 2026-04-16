#include <bits/stdc++.h>

using namespace std; 

#define MAX 26
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

int main (){
    string s; cin >> s;
    vector<int> freq(MAX); 
    for(int i = 0; i < s.size(); i++){
        freq[s[i] - 'A']++; // A -> 0, B -> 1...        
    }
    
    //verifica se eh possivel
    bool possible = 1;
    int even = 0, ind; 
    for(int i = 0; i < freq.size(); i++){ //26
        if(s.size() % 2){
            if(freq[i] % 2){ //se o numero de caracteres for impar, entao, so um caracter pode ter quantidade impar
                even++; ind = i;
            }                         
        }    
        else{
            if(freq[i] % 2) //se o numero de caracteres na string for par, então todos os caracteres precisam ter quantidade par
                possible = 0;
        }            
    }


    deque<char> ans; 

    if(even > 1 || !possible){ //se eu tiver visto mais de um caractere de f impar ou algum caractere na string par tiver f impar
        cout << "NO SOLUTION" << endl; 
        return 0;
    } 
    
    else{       
        
        //complexidade -> o(n)
        if(even){                
            for(int j = 0; j < freq[ind]; j++){             
                ans.push_back((char) 'A' + ind);                     
            }      
        }      
        for(int i = 0; i < freq.size(); i++){ //complexidade -> 26 * o(n); 
            if(freq[i] % 2) continue; 
            for(int j = 0; j < freq[i]; j+=2){
                ans.push_back((char)'A' + i); 
                ans.push_front((char)'A' + i);
            }
        }
        
    }

    for(auto k: ans) cout << k; 


}