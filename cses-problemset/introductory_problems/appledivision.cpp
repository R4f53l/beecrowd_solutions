#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

vector<int> v;
int n;
long long ans = 0x3f3f3f3f;

void backtrack(int i, long long group_sum1, long long group_sum2){    
    if(i == n){        
        ans = min(ans, abs(group_sum1 - group_sum2));
        return;
    }
    backtrack(i + 1, group_sum1 + v[i], group_sum2);
    backtrack(i + 1, group_sum1, group_sum2 + v[i]);
}

int main(){_
    cin >> n;     
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.push_back(a);
    }
    //a ideia é testar todas as possibilidades de soma. Como? com backtrack
    backtrack(0, 0, 0);
    cout << ans << endl;
}