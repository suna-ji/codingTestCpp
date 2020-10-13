// 격자상의 경로 - 10164
// 해당 조건을 만족하는 경로의 개수
// 조건1: 오른쪽, 아래로만 이동 가능
// 조건2: 동그라미 표시된 격자는 반드시 지날 것
#include <iostream>
#include <cstring>
#define MAX 15 + 2
using namespace std;
int N, M, K;
int map[MAX][MAX];
long long memo[MAX][MAX];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int Cx, Cy; // 동그라미 표시된 좌표
// (x + 1, y + 0)아래 (x+0, y+1)오른쪽
int EndX, EndY;
long long dfs(int x, int y){
    if(x == EndX && y == EndY){
        return 1;
    }
    if(memo[x][y] != -1){
        return memo[x][y];
    }
    memo[x][y] = 0;
    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && nx <= EndX && ny >= 1 && ny <= EndY){ // 범위 체크
            memo[x][y] = memo[x][y] + dfs(nx, ny);
        }
    }
    return memo[x][y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> N >> M >> K;
    if(K > 0){
       
        if(K % M == 0){
            Cx = K / M;
            Cy = M;
        }else{ 
            Cx = K/ M + 1;
            Cy = K % M;
        }
    }
    // 동그라미 위치 계산
    memset(memo, -1, sizeof(memo));
    if(K == 0 || K == 1 || K == N * M){// 동그라미 없음
        EndX = N;
        EndY = M;
        dfs(1, 1);
        cout << memo[1][1];
    }else{ // 동그라미 있음
        EndX = Cx;
        EndY = Cy;
        dfs(1, 1);
        long long beforeCircle = memo[1][1];
        memset(memo, -1, sizeof(memo));
        EndX = N;
        EndY = M;
        dfs(Cx, Cy);
        long long afterCircle = memo[Cx][Cy];
        long long result = beforeCircle * afterCircle;
        cout << result;
    }
}
// 동그라미가 여러곳에 있는경우는 어쩌지..
