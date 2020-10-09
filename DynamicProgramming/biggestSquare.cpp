// 가장 큰 정사각형 - 1915
// 그냥 영역의 크기를 구하는게 아니라, 정사각형을 구해야함!
// 프로그래머스 강의 들었음
// 다시 풀어보자..
#include <iostream>
#include <algorithm>
#define MAX 1000 + 2
using namespace std;

int N, M;
int map[MAX][MAX];
int memo[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%1d", &map[i][j]); // 연속된 숫자를 하나씩 분리해서 받기
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(map[i][j] != 0){ // 1이라면
                memo[i][j] = min(memo[i-1][j], memo[i][j-1]);
                memo[i][j] = min(memo[i][j], memo[i-1][j-1]) + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            ans = max(ans, memo[i][j]);
        }
    }
    cout << ans * ans;
}