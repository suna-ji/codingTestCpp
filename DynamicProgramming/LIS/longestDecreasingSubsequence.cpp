// 가장 긴 감소하는 부분 수열 - 11722
#include <iostream>
#define MAX 1000 + 3
using namespace std;
int N;
int numArr[MAX];
int memo[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    }
    // 입력
    // memo[i] : 1부터 i까지의 가장 긴 감소하는 부분 수열의 길이
    for(int i = 1; i <= N; i++){
        memo[i] = 1; 
        for(int j = 1; j < i; j++){
            if(numArr[i] < numArr[j] && memo[i] < memo[j] + 1){ // 감소하는 부분 수열
                memo[i] = memo[j] + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, memo[i]);
    }
    cout << ans;
    // 출력
}