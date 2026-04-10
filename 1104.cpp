#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL); 

int main (){_    
    int a, b; 
    while(cin >> a >> b, a && b){
        int c; 
        set<int> al, be; 
        for(int i = 0; i<a; i++){
            cin >> c; 
            al.insert(c); 
        }
        for(int j = 0; j<b; j++){
            cin >> c; be.insert(c);
        }
        set<int> ans; 
        if(al.size() > be.size())
            set_difference(be.begin(), be.end(), al.begin(), al.end(), inserter(ans, ans.begin()));  //diferença entre o set be - al. No inserter passamos o container e um iterator pro inicio.
        else 
            set_difference(al.begin(), al.end(), be.begin(), be.end(), inserter(ans, ans.begin()));    
        cout << ans.size() << endl;        

        
    }

}