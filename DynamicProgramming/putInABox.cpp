// 상자넣기 - 1965
// 가장 긴 증가하는 부분 수열문제랑 똑같음
#include <iostream>
#include <algorithm>
#define MAX 1000 + 3
using namespace std;
int N;
int numArr[MAX];
int memo[MAX]; // memo[i]: 길이가 i일때, 가장 긴 증가하는 부분 수열
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    }

    for(int i = 1; i <= N; i++){
        memo[i] = 1;
        for(int j = 1; j < i; j++){
            if(numArr[j] < numArr[i] && memo[i] < memo[j]+ 1){
                memo[i] = memo[j] + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, memo[i]);
    }
    cout << ans;
}