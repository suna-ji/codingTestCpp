// 점프 - 1890
// 풀었지만..내리막 길(1520)번 없었으면 못풀었을듯..
// 이것도 경로의 개수 구하는 문제
#include <iostream>
#include <cstring>
#define MAX 100 + 3
using namespace std;
int N;
int map[MAX][MAX];
long long memo[MAX][MAX];
long long dfs(int x, int y){
    if(x == N && y == N) return 1;
    if(memo[x][y] != -1) return memo[x][y];
    memo[x][y] = 0;
    int nx = x + map[x][y];
    int ny = y + map[x][y];
    if(nx >= 1 && nx <= N){
        memo[x][y] = memo[x][y] + dfs(nx, y);
    }// 아래로
    if(ny >= 1 && ny <= N){
        memo[x][y] = memo[x][y] + dfs(x, ny);
    }// 오른쪽으로 
    return memo[x][y];
}
// memo처음에 -1로 초기화 한번 방문시 0으로 변경하고 + dfs
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    memset(memo, -1, sizeof(memo));
    for(int i =1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }
    long long ans = dfs(1,1);
    cout << ans;
}