// 가장 긴 증가하는 부분 수열2 - 12015
// 가장..수열1 보다 메모리 제한이 넉넉하지만 N의 길이가 늘어났음
// dp로 못푼당.. -> LIS알고리즘 하는날 다시
#include <iostream>
#include <algorithm>
#define MAX 1000000 + 2
using namespace std;
int N;
int numArr[MAX];
int memo[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        memo[i] = 1;
        for(int j = 1; j < i; j++){
            if(numArr[j] < numArr[i] && memo[i] < memo[j] + 1){
                memo[i] = memo[j] + 1;
            }
        }
        ans = max(ans, memo[i]);
    }
    cout << ans;
}