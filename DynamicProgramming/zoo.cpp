// 동물원 - 1309
// 실버1인데 너무한거 아니냐..
// 그래프 문제처럼 접근했는데 포도주같은 문제

#include <iostream>
#define MAX 100000 + 2
using namespace std;
int N;
int memo[MAX][3];
// memo[i][0] i번째 줄에 사자 한마리도 없음
// memo[i][1] 1번째 줄에 사자 왼쪽 칸에 있음
// memo[i][2] i번째 줄에 사자 오른쪽 칸에 있음

int main(){
    cin >> N;
    for(int i = N; i >= 1; i--){
        memo[i][0] = memo[i-1][0] + memo[i-1][1] + memo[i-1][2];
        memo[i][1] = memo[i-1][0] + memo[i-1][2];
        memo[i][2] = memo[i-1][0] + memo[i-1][1];
    }

    cout << memo[1][0] + memo[1][1] + memo[1][2];

}