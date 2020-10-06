// 이동하기 - 11048
// 이동하며 가져올 수 있는 사탕의 최댓값을 출력
#include <iostream>
#include <algorithm>
#define MAX 1000 + 3
using namespace std;

int N, M;
int map[MAX][MAX];
long long memo[MAX][MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
        }
    }
    // input finish
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            memo[i][j] = max(memo[i][j], memo[i-1][j-1]);
            memo[i][j] += map[i][j];
        }
    }
    cout << memo[N][M];
}