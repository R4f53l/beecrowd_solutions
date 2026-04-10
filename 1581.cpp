#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k; 
    bool m = false; 
    string s; 
    cin >> n;
    getchar ();
    while(n--){
        cin >> k;
        getchar();
        cin >> s;
        for(int i=0; i<k; i++){
            if(s[0]!=s[i])
                m = true;            
        }
        if(m)
            cout << "ingles" << endl;
        else 
            cout << s << endl;
    }




    return 0;
}