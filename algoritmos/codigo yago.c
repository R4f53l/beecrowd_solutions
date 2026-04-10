#include <stdio.h>

#define MAX 130
#define MAXQ 100000

typedef struct{
    int x, y;
}point;

int n, m, k;
char t[MAX][MAX];

int dx[] = {1, 2, 2, 1, -1, -2,-2,-1};
int dy[] = {2, 1,-1,-2, -2, -1, 1, 2};

int inGrid(int x, int y){
    if(x < 0 || x >= m ||y < 0|| y >= n){
        return 0;
    }
    return (t[y][x] != '#'); 
}

int main(){
    while(scanf("%d %d %d", &n, &m, &k), n){
        int ans = 0;
        point start, act;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                scanf(" %c", &t[i][j]);

                if(t[i][j] == 'C'){
                    start.x = j, start.y = i;
                }
            }
        }

        act = start;

        for(int i = 0; i<=k; i++){
            point q[MAXQ];
            int front = 0, rear = 0;
            int d[MAX][MAX], vi[MAX][MAX] = {};

            if(i == k) t[start.y][start.x] = 'P';

            q[rear++] = act;
            d[act.y][act.x] = 0;
            vi[act.y][act.x] = 1;

            while(front < rear){
                point top = q[front++];

                for(int i = 0; i<8; i++){
                    point tmp = {top.x + dx[i], top.y + dy[i]};

                    if(!vi[tmp.y][tmp.x] && inGrid(tmp.x, tmp.y)){
                        if(t[tmp.y][tmp.x] != 'P'){
                            q[rear++] = tmp;

                            d[tmp.y][tmp.x] = d[top.y][top.x] + 1;
                            vi[tmp.y][tmp.x] = 1;

                        } else {
                            act.x = tmp.x, act.y = tmp.y;
                            ans += d[top.y][top.x] + 1;
                            t[tmp.y][tmp.x] = '.';
                            rear = -1;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);        
    }
}