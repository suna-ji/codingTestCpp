// 오르막 수 - 11057
// 쉬운 계단 수 - 10844번과 유사 
// 수의 길이 N이 주어졌을 때, 오르막 수의 개수
// 그래서 memo[i][j]를 길이가 i일때, j로 끝나는 오르막 수의 개수로 잡았는데
// 걔산한 memo를 다음 계산에서 어떻게 써야하는지 감이 안왔다.
// 블로그 참고한 결과 3중 for문을 사용했다.
#include <iostream>
#define MAX 1000 + 3
using namespace std;
int N;
long long memo[MAX][10]; // memo[i][j] -> 길이가 i일때, j로 끝나는 오르막 수 개수
int main(){
    cin >> N;
    for(int i = 0; i <= 9; i++){
        memo[1][i] = 1;
    }// 길이 1일때 memo 계산

    for(int i = 2; i <= N; i++){ // 길이 2~N까지의 memo계산
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= j; k++){
                memo[i][j] = memo[i][j] + memo[i-1][k];
                memo[i][j] = memo[i][j] % 10007;
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i <= 9; i++){
        ans += memo[N][i];
    }
    ans = ans % 10007; // 100007로 했다가 4번 틀렸네..
    cout << ans;
}
