// 01타일 - 1904
#include <iostream>
#define MAX 1000000 + 3
using namespace std;
int memo[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    memo[1] = 1;
    memo[2] = 2;
    // 3부터 dp시작
    for(int i = 3; i <= N; i++){
        memo[i] = (memo[i-1] + memo[i-2]) % 15746;
        // memo[i-1]뒤에 1만 붙음 -> 그대로 경우의 수는 memo[i-1]
        // memo[i-2]뒤에 00붙음 -> 그대로 경우의 수는 memo[i-2]
    }
    cout << memo[N];
}