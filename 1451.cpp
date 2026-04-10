#include <bits/stdc++.h> 
using namespace std; 

int main() {
    string s; 
    while(getline(cin, s)){
        list <char> l; 
        list <char>::iterator it = l.begin ();
        int a = 0; 
        for(auto &k:s){
            if(k == '['){
                it = l.begin();
                a = 1;
            }
            else if(k == ']')
                a = 0; 
            else {
                if(a)
                    l.insert(it, k);
                else 
                    l.push_back(k);
            }
        }
        for(auto &c:l)
            cout << c; 
        cout << endl; 
    }

    return 0;
}
