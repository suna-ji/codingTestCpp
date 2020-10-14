// 합분해 - 2225
// 0부터 N까지의 정수 K를 더해서 그 합이 N이 되는 경우의 수
// 덧셈의 순서가 바뀐 경우는 다른 경우
// 또한 한 개의 수를 여러 번 쓸수있다.
#include <iostream>
#define MAX 200 + 2
using namespace std;
int N, K;
long long memo[MAX][MAX]; //memo[i][j]: i개를 더해서 j를 만드는 경우의 수
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>  N >> K;

    for(int i = 0; i <= N; i++){
        memo[1][i] = 1;
    }// 초기화! memo[1][N] : 1개를 더해서 N을 만드는 경우의 수 -> 무조건 1
    // memo[K][N] = memo[K-1][0] + memo[k-1][1] + ... + memo[k-1][N]
    for(int a = 2; a <= K; a++){
        for(int b = 0; b <= N; b++){
            for(int c = 0; c <= b; c++){
                memo[a][b] = (memo[a][b] + memo[a - 1][c]) % 1000000000;
            }
        }
    }
    cout << memo[K][N] % 1000000000;
}