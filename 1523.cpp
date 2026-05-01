#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    while(cin >> n >> k && (n || k)) {
        stack<int> q;
        bool erro = false;

        for(int i = 0; i < n; i++) {
            int c, s; cin >> c >> s;
            
            while(!q.empty() && q.top() <= c) {
                q.pop();
            }

            
            if(q.size() >= k) erro = true;

            
            if(!q.empty() && s > q.top()) erro = true;

            q.push(s);
        }

        if(erro) cout << "Nao" << endl;
        else cout << "Sim" << endl;
    }
    return 0;
}