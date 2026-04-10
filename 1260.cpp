#include<bits/stdc++.h> 
using namespace std;

int main(){
    int n; 
    cin >> n; 
    getchar();
    getchar();
    cout << setprecision(4) << fixed;
    while(n--){
        map<string, int> m; 
        map<string, int> :: iterator it;
        string s; 
        int t = 0;
            while(getline(cin, s)){
                if(s.empty())
                    break;
                m[s]++;
                t++;
                
            }
            /*for(&[n, p]: m){
                cout << n << " " << 100.0*p/t << endl;
            }
                 */
            for(it=m.begin(); it!=m.end(); ++it)
                cout << it->first << " " << 100.0*it->second/t << endl;   
            
            
            if(n)
                cout << endl;
        
    }
    

    
}