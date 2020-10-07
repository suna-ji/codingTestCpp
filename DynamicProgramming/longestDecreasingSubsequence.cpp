// 가장 긴 감소하는 부분 수열 - 11722
#include <iostream>
#define MAX 1000 + 3
using namespace std;

int N;
int numArr[MAX];
int memo[MAX];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        memo[i] = 1; 
        for(int j = i-1; j >= 1; j--){
            if(numArr[j] > numArr[i]){ // 감소하는 수열이라면
                memo[i] = max(memo[i], memo[j] + 1);
            } 
        }
        ans = max(memo[i], ans);
    }
    cout << ans;
}