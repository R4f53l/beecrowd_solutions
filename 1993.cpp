#include <bits/stdc++.h> 
using namespace std; 
int main () {
    int n, i, cont = 0;
    cin >> n; 
    while(n--){
        cont++;
        char s1 [100], s2[100];
        int x;         
        scanf(" %s %s", s1, s2);
        if(s2[0] == 'd'){
            sscanf(s1, "%d", &x);
        }
        else if(s2[0] == 'h'){
            sscanf(s1, "%x", &x);
        }
        if(s2[0]=='d'){
            vector<int> v;
            printf("%x hex\n", x);
            while(x){
                v.push_back(x%2);
                x/=2;
            }
            reverse(v.begin(), v.end());
            for(i=0; i<v.size(); i++)
                printf("%d", v[i]);
            printf("bin\n");
        }
        if(s2[0]=='h'){
            vector<int> v;
            printf("%d dec\n", &x);
            int n = x; 
            while(x){
                v.push_back(x%2);
                x/=2;
            }
            reverse(v.begin(), v.end());
            for(i=0; i<v.size(); i++)
                printf("%d", v[i]);
            printf("bin\n");

        }
        if(s2[0]=='b'){
            int b = 0; 
            for(i=0; s1[i]; i++){
                b*=2; 
                if(s1[i]=='1') b++;
            }
            printf("%d dec\n", b);
            printf("%x hex\n", b);
        }
        
    }




    return 0;
}