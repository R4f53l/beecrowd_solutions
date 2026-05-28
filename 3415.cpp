#include <bits/stdc++.h> 

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0); 

#define MAX 21

int main(){_
    int n; cin >> n; 
    vector<double> points(5, 0); 
    vector<int> erros(5, 0); 
    while(n--){        
        string teacher, student; cin >> teacher;       
        int menor = 1e9; 
        for(int z = 0; z < 5; z++){
            int dp[MAX][MAX]; 
            
            for(int i = 0; i <= teacher.size(); i++)
                dp[0][i] = i; 
         
            cin >> student;             
            for(int j = 0; j <= student.size(); j++)
                dp[j][0] = j; 
                
            
            
            for(int i = 1; i <= student.size(); i++){
                for(int j = 1; j <= teacher.size(); j++){
                    if(teacher[j - 1] == student[i - 1]) dp[i][j] = dp[i - 1][j - 1]; 
                    else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;  
                }
                
            }                  
           
            erros[z] = (dp[student.size()][teacher.size()]); 
            menor = min(dp[student.size()][teacher.size()], menor);           
            
        }
        
        for(int i = 0; i < 5; i++){            
            if(erros[i] == menor && !menor) points[i] += 1.0; 
            else if(erros[i] == menor) points[i] += 0.5;
        }
        


    }


    double maior = -1;
    for(auto k: points)
        maior = max(maior, k); 

    cout << fixed << setprecision(1);
    cout << maior << endl;
    vector<int> students; 

    for(int i = 0; i < 5; i++)
        if(points[i] == maior) students.push_back(i + 1); 

    for(int i = 0; i < students.size(); i++){            
        cout << students[i]; 
        if(i < students.size() - 1) cout << " "; 
    }

    cout << endl;
}