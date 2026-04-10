#include <bits/stdc++.h> 

using namespace std; 

#define MAX 3
char board [MAX][MAX]; 

void print_board(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            cout << board[i][j]; 
        cout << endl;
    }
}

bool has_space (){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            if(board[i][j] == '#') return true;
    }
    return false; 
}

bool checkWinner (){
    
   



}

int main (){

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            board[i][j] = '#';
    }
    while(has_space()){
        print_board();
        cout << "Escreva a posicao (i, j) que voce deseja posicionar o X" << endl;
        int i, j; 
        do{
            cin >> i >> j;
        }while(board[i][j] != '#');        
    }

}