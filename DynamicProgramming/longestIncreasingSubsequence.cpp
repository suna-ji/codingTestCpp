// 가장 긴 증가하는 부분 수열 - 11053
#include <iostream>
#define MAX 1000+3
using namespace std;
int N;
int memo[MAX];
int numArr[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    }
    // 입력
    int Answer = 0;
    for(int i = 0; i <= N; i++){
        memo[i] = 1;
        for(int j = i-1; j >= 1; j--){
            if(numArr[i] > numArr[j]){
                memo[i] = max(memo[i], memo[j] + 1); // 이전까지의 memo중에서 가장 큰 값을 현재의 memo로 지정
            }
        }
        Answer = max(memo[i], Answer); // 지정된 memo[i]와 Answer중 큰 값을 answer에 지정
    }
    // 로직
    cout << Answer;
    // 출력
}