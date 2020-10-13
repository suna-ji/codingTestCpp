// RGB거리 - 1149
// 시간제한 0.5초
// 각 집을 빨강, 초록, 파랑으로 칠하는 비용은 모두 다르다 -> 각 집을 칠하는 최소 비용을 구해라
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000 + 3
using namespace std;

int N;
int rgbPrice[MAX][3];
int memo[MAX][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            cin >> rgbPrice[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        memo[i][0] = min((memo[i-1][1] + rgbPrice[i][0]), (memo[i-1][2] + rgbPrice[i][0])); 
        // i번째 집을 빨강으로 칠하는 경우 -> (i-1번째 집을 초록으로 칠하는 비용 + i번째 집 빨강으로 칠하는 비용) 과 (i-1번째 집을 파랑으로 칠하는 비용 + i번째 집 빨강으로 칠하는 비용) 중에 작은거
        memo[i][1] = min((memo[i-1][0] + rgbPrice[i][1]), (memo[i-1][2] + rgbPrice[i][1])); 
        memo[i][2] = min((memo[i-1][0] + rgbPrice[i][2]), (memo[i-1][1] + rgbPrice[i][2])); 
    }
    int ans = 99999999;
    for(int i = 0; i < 3; i++){
        ans = min(ans, memo[N][i]);
    }
    cout << ans;

}