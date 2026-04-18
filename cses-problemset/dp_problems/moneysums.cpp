#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 100100

int main(){_
    int n, sum = 0; cin >> n; 
    vector<int> v(n), values(MAX);
    for(auto &i: v){
        cin >> i; sum += i;               
    }

    
    values[0] = 1; 
    int cont = 0; 
    //2 8 sum = 10; 10 - 2 = 8, false. 10 - 8 = 2
    //8 - 2 = 6 4 - 2 = 2 
    for(int i = 0; i < v.size(); i++){ //2
        for(int j = sum; j >= 0; j--){ //2 8            
            if(j - v[i] >= 0 && values[j - v[i]]){
                if(!values[j]) cont++;
                values[j] = 1;    
            }
        }
    }    

    cout << cont << endl; 

    for(int i = 1; i < values.size(); i++)
        if(values[i]) cout << i << " ";

}