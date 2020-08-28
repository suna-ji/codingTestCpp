// 1012번- 유기농배추
#include <iostream>
#include <stdio.h>
#include <cstring> // memset
using namespace std;

int cnt = 0;
int M, N; // boundary 체크
bool visit[50][50];
int map[50][50];
int dx[] = {0, 0, -1, 1}; 
int dy[] = {-1, 1, 0, 0};
// 상하좌우
void dfs(int y, int x){
    visit[y][x] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < M && ny < N){
            if(map[ny][nx] && !visit[ny][nx]){
                dfs(ny, nx);
            }
        }
    }
}

int main(){
    int T;
    cin >> T;
    int K, x, y;
    for(int i = 0; i < T; i++){
        scanf("%d %d %d", &M, &N, &K);

        memset(map, 0, sizeof(map));// map초기화
        memset(visit, false, sizeof(visit)); // visit 초기화
        for(int j = 0; j < K; j++){
            scanf("%d %d", &x, &y); 
            map[y][x] = 1;
        }
        cnt = 0;
        for(int j = 0; j < N; j++){ //  세로 x
            for(int k = 0; k < M; k++){ //  가로 y
                if(map[j][k] && !visit[j][k]) { // 배추가 있고 방문하지 않았으면
                    cnt++;
                    dfs(j, k);
                }
            }
        }
        cout << cnt << endl;
    }
}