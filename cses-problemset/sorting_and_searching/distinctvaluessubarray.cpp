#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){_
    int n;
    cin >> n;

    vector<int> v(n);

    set<int> s;

    int l = 0;
    long long cont = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];

        while(s.count(v[i])){
            s.erase(v[l]);
            l++;
        }

        s.insert(v[i]);

        cont += s.size(); 
    }

    cout << cont << '\n';
}