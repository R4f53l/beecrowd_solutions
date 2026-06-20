#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

template<typename T>
using ordered_set =
tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    int n, k; cin >> n >> k; 
    ordered_set <int> s;
    for(int i = 1; i <= n; i++)
        s.insert(i); 
    
    int pos = k % n; 

    while(!s.empty()){
        auto it = s.find_by_order(pos); 
        cout << *it << " "; 
        s.erase(it);         
        if(!s.empty()) pos = (pos + k) % s.size(); 
    }
    cout << endl;
}
