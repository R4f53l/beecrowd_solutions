#include <bits/stdc++.h> 

using namespace std; 
#define inf 0x3f3f3f3f
const int MAX = 310, MAXW = 55; 

vector<int> qt, w; 
int memo[MAX][MAXW], q; 
vector<bool> peguei; 

int dp (int i, int cap){
    if(cap < 0) return -inf;
    if(i == q) return 0;
    int &p = memo[i][cap]; 
    if(p != -1) return p; 
    return p = max(dp(i+1, cap), dp(i+1, cap - w[i]) + qt[i]); 
}

void recup (int i, int cap){
    if(i == q) return; 
    if(cap >= w[i] && dp(i+1, cap) < dp(i+1, cap-w[i]) + qt[i]){
        peguei[i] = 1; 
        recup(i+1, cap-w[i]); 
    }
    else recup(i+1, cap); 
}

int main (){
    int n; cin >> n;
    while(n--){
        cin >> q; 
        qt = vector<int> (q), w = vector<int> (q);  
        for(int i = 0; i<q; i++)
            cin >> qt[i] >> w[i]; 
        memset(memo, -1, sizeof(memo)); 

        cout << dp(0, 50) << " brinquedos" << endl; 
        int c = 0, peso = 0; 
        peguei = vector<bool> (q, false);
        recup(0, 50);
        for(int i = 0; i<q; i++){
            if(peguei[i]){
                c++; peso += w[i];
            }
        }
        cout << "Peso: " <<  peso << " kg" << endl; 
        cout << "sobra(m) "<< q - c << " pacote(s)" << endl;  
        cout << endl;    
    }
}