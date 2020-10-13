// 내리막 길 - 1520
// 경로의 개수 구하는 문제
#include <iostream>
#include <cstring>
#define MAX 500 + 2
using namespace std;

int M, N;
int map[MAX][MAX]; 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
//상하좌우 이동 가능
int memo[MAX][MAX]; // memo[i][j] i, j에서 시작해서 M, N에 도착하는 경로의 경우의 수

int dfs(int x, int y){
    if(x == M && y == N){
        return 1;
    } // 원래는 여기서 cnt++했는데 지금은 1을 리턴해서 memo에 더하는 방식으로..!
    if(memo[x][y] != -1){
        return memo[x][y];
    } 
    memo[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && nx <= M && ny >= 1 && ny <= N){
            if(map[x][y] > map[nx][ny]){
                memo[x][y] = memo[x][y] + dfs(nx, ny);
            }
        }
    }
    return memo[x][y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //빠른 입출력
    cin >> M >> N;
    memset(memo, -1, sizeof(memo));
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }
    dfs(1, 1);
    cout << memo[1][1];
}