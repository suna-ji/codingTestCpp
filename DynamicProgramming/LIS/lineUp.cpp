// 줄세우기 - 2631
// 전기줄 문제처럼 LIS 응용문제같음!
#include <iostream>
#include <algorithm>
#define MAX 200 + 3 
using namespace std;
int N;
int numArr[MAX];
int memo[MAX];
int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    }
    for(int i = 1; i <= N; i++){
        memo[i] = 1; 
        for(int j = 1; j < i; j++){
            if(numArr[j] < numArr[i] && memo[j] + 1 > memo[i]){
                memo[i] = memo[j] + 1;
            }
        }
    }
    int maxLIS = -999;
    for(int i = 1; i <= N; i++){
        maxLIS = max(maxLIS, memo[i]);
    }
    int ans;
    ans = N - maxLIS;
    cout << ans;
}