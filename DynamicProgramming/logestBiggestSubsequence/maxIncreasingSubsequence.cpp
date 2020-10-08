// 가장 큰 증가 부분 수열 - 11055
// 아 너무 어려웠다..
#include <iostream>
#define MAX 1000 + 3
using namespace std;
// 수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구해라
// {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} -> 1 2 50 60
int memo[MAX]; // memo[i] : 길이 i 일때 가장 큰 값
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int numArr[MAX];
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    }
    
    for(int i = 1; i <= N; i++){
        memo[i] = numArr[i];
        for(int j = 1; j < i; j++){
            if(numArr[j] < numArr[i] && memo[i] < memo[j] + numArr[i]){
                memo[i] = memo[j] + numArr[i];
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, memo[i]);
    }
    cout << ans;
}
