// 내리막 길 - 1520
#include <iostream>
#define MAX 500 + 2
using namespace std;

int M, N;
int map[MAX][MAX];
int visit[MAX][MAX];
int cnt = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
//상하좌우 이동 가능

void dfs(int x, int y){
    visit[x][y] = true;
    if(x == M && y == N){
        cnt++;
        return;
    }// 도착지점
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && nx <= M && ny >= 1 && ny <= N){
            if(!visit[nx][ny] && map[x][y] > map[nx][ny]){
                dfs(nx, ny);
                visit[nx][ny] = false; // dfs빠져나왔을때는 false로 다시 설정해줘야함!!
            }
        }
    }
}// 시간초과
//한 정점에서 4방향 모두 탐색 -> 4^(500 * 500)의 탐색 필요

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //빠른 입출력
    cin >> M >> N;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }
    dfs(1, 1); 
    cout << cnt;
}