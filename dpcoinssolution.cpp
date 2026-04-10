#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define inf 0x3f3f3f3f
#define MAX 10000
vector<int> moedas = {1, 3, 4}; 
vector<int> troco(MAX, inf); 
vector<int> last_one (MAX); 

int main (){
    int x = 9; 
    troco[0] = 0; 
    for(int i = 0; i < moedas.size(); i++){
        for(int j = moedas[i]; j <= MAX; j++){
            if(troco[j] > troco[j - moedas[i]] + 1){
                troco[j] = troco[j - moedas[i]] + 1;
                last_one[j] = moedas[i]; 
            }
        } 
    }

    vector<int> solution; 
    while(x > 0){   
        solution.push_back(last_one[x]); 
        x -= last_one[x]; 
    }

    for(auto i: solution)
        cout << i << " "; 

    cout << endl;  
}