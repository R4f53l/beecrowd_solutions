#include <bits/stdc++.h> 

using namespace std; 

int main() {
    priority_queue <string, vector<string>, greater <string>> l; 
    string s, o;  
    while(scanf("%[^\n]", s), s != "0"){
        char aux = getchar();
        cout << s << endl; 
        if(aux == '\n'){
            for(int i = 0; s[i]; i++){
                if(isalpha(s[i]))
                    o += tolower (s[i]);
                else {
                    l.push (o);
                    o.clear();
                }
            }
        }
    }
    while(!l.empty()){
        cout << l.top() << endl; 
        l.pop();
    }
    return 0;
}
