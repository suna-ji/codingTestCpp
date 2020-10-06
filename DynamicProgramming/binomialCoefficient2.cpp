// 이항계수 2 - 11051
#include <iostream>
#include <cstring>
#define MAX 1000 + 3
using namespace std;
// 이항계수 항등식
// 1 (N K) = (n n-k)
// 2 (N K) + (n K+1) = (N+1 K+1)
// 즉, memo[N][k] = memo[N-1][k-1] + memo[N-1][k] 

int N, K;
int map;
int memo[MAX][MAX];

int main(){
    cin >> N >> K;
    // 초기값은 다음과 같다.
    // K가 1이면 무조건 N
    // N == K 이면 무조건 1
    // k가 0이면 무조건 1
    for(int i = 1; i <= N; i++){
        memo[i][1] = i;
        memo[i][i] = 1;
        memo[i][0] = 1;
    }
    for(int i = 3; i <= N; i++){ // K가 2부터 시작이니까 자연스럽게 N은 3부터 시작
        for(int j = 2; j < i; j++){  // k가 1인 경우는 위에서 처리 -> 2부터 시작  // 또한, N은 K보다 같거나 커야하는데 같으 경우는 위에서 처리 
            memo[i][j] = (memo[i-1][j-1] + memo[i-1][j]) % 10007;
        }    
    }
    cout << memo[N][K];
}