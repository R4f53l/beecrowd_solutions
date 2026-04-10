#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

// problema N queens p n > 9...  
//a ideia sera usar bitmask e backtracking 

//imagine uma matriz 3 x 3: os indices dela sao: 
//(0, 0), (0, 1), (0, 2)
//(1, 0), (1, 1), (1, 2)
//(2, 0), (2, 1), (2, 2)

//Um padrão notável nessa matriz eh o seguinte: se somarmos os indices de cada posicao
//obtemos o seguinte: 
//(0+0)=0, (0+1)=1, (0+2)=2
//(1+0)=1, (1+1)=2, (1+2)=3
//(2+0)=2, (2+1)=3, (2+2)=4

//Se subtrairmos r - c, obtemos: 
//(0-0)=0, (0-1)=-1, (0-2)=-2
//(1-0)=1, (1-1)=0, (1-2)=-1
//(2-0)=2, (2-1)=1, (2-2) = 0
//Nesse caso, eh possivel notar que os valores vão de 2 a -2, ou seja, de (n-1) a -(n-1)
//Logo, para representar isso, precisamos de algo com tamanho de (n-1) - (-(n-1)) + 1 = 2n -1

//bom, não temos valores negativos, então, para esse caso, teremos cada indice como: r-c + n -1 ( diagonal secundária)
//para a diagonal principal, o indíce é r + c; 

bitset <30> rw, dig1, dig2;
int ans = 0, n = 5; 

void backtrack (int c){
    if(c == n){
        ans++; 
        return; 
    }
    
    for(int i = 0; i < n; i++){
        if(!rw[i] && !dig1[i + c] && !dig2[i - c + n - 1]){
            rw[i] = dig1[i + c] = dig2[i - c + n - 1] = true; 
            backtrack(c + 1); 
            rw[i] = dig1[i + c] = dig2[i - c + n - 1] = false; 
        }
        
    }
    
}

int main (){
    backtrack(0); 
    cout << ans << endl; 
}