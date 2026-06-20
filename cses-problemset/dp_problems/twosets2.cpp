#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

const int mod = 1e9 + 7; 

long long fast_exponentiation (int base, int expo){
    if(expo == 0)
        return 1;     
    long long result = fast_exponentiation(base, expo / 2); 
    //3 ^10, (3 ^5) ^2, (3 ^2)^2 * 3;
    if(expo%2){
        return (((result * result) % mod) * base) % mod; 
    }
    else{
        return (result * result) % mod; 
    }
}

int main(){_
    int n; cin >> n;
    int size = (n * (n + 1))/ 2;
    if(size % 2){
        cout << 0; 
        return 0; 
    }
    size /= 2; 
    vector<int> trocos(size + 1, 0);     
    trocos[0] = 1; 
    for(int i = 1; i <= n; i++){
        for(int j = size; j >= i; j--){
            trocos[j] = (trocos[j] + trocos[j - i]) % mod; 
        }
    }
    //basicamente essa eh a ideia, uma delas pelo menos
    //porem, dessa forma, contamos nossa resposta com o valor dobrado
    //para resolver isso, nao podemos simplesmente dividir por 2, pq nosso valor eh calculado
    //com base no modulo mod. Fazer ans / 2 não nos daria nossa resposta
    //para fazer isso, precisamos dividir (ou multiplicar), pelo inverso modular
    //de 2
    //tem um teorema que diz que se mod eh primo, ent
    //a ^ - 1 = a ^mod -2 % mod
    //ou seja, 2 ^ - 1 = 2 ^ (1e9 + 5) % mod; 
    //que daria 5 * 10 ^8 + 4;
    //para calcularmos isso de forma geral, podemos usar exponenciacao rapida
    cout << (trocos[size] * fast_exponentiation(2, mod - 2)) % mod << endl; 
}