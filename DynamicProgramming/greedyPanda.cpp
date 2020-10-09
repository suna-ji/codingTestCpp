// 욕심쟁이 판다 - 1937
// 이동 조건: 이전 지역보다 대나무 많아야함
// 이동 못하면 거기서 단식 -> 죽늗다
// 판다가 최대한 살 수 있는 일수를 출력
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 500 + 3
using namespace std;
int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// 상하좌우
int map[MAX][MAX];
int memo[MAX][MAX]; 
// memo[i][j] : i.j에서 풀어놨을경우 최대한 살 수 있는 일수 
// map[i][j]와 새로운 시작 지점 비교해서 만약 새로운 시작 지점이 더 크다면 
// memo[nx][ny] = memo[i][j] + 1

int dfs(int x, int y){
    if(memo[x][y] != -1){
        return memo[x][y];
    }
    memo[x][y] = 1; // 해당 좌표를 1로 설정하고 탐색 진행
    // 어느 좌표든 판다가 1일은 살 수 있기 때문.
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && nx <= N && ny >= 1 && ny <= N){
            if(map[x][y] < map[nx][ny]){
                memo[x][y] = max(memo[x][y], dfs(nx, ny) + 1); // dfs(nx, ny) + 1 이게 중요!!
                // 경우의 수 문제는 memo[x][y] = memo[x][y] + dfs(nx, ny);
            }
        }
    }
    return memo[x][y];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
}
