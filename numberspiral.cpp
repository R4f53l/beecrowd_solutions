#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        long long y, x;
        cin >> y >> x;
        y--, x--; 
        long long ans;

        if (x > y) {
            if (x % 2)
                ans = x*x + y + 1;
            else
                ans = (x+1)*(x+1) - y;
        } 

        else {
            if (y % 2)
                ans = (y + 1) * (y + 1) - x;
            else
                ans = y * y + x + 1;
        }

        cout << ans << "\n";
    }
}