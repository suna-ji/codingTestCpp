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
    // int Answer = 0;
    // for(int i = 0; i <= N; i++){
    //     memo[i] = 1;
    //     for(int j = i-1; j >= 1; j--){// 자기보다 이전에 잇는 원소들 중에서 작은 원소를 찾고 // 자신보다 바로 이전에서만 이어지는게 아니라 이전에 있는 원소들 중 작은 원소면 무조건 이어질 수 있으니까 다 돌아봐야함
    //         if(numArr[i] > numArr[j]){ // 그 원소를 선택했을 때, 현재 자기자신의 증가하는 부분수열의 크기보다 크다면 갱신
    //             memo[i] = max(memo[i], memo[j] + 1); // 이전까지의 memo중에서 가장 큰 값을 현재의 memo로 지정
    //         }
    //     }
    //     Answer = max(memo[i], Answer); // 지정된 memo[i]와 Answer중 큰 값을 answer에 지정
    // }
    // 로직
    // for(int i = 0; i <= N; i++){
    //     memo[i] = 1;
    //     for(int j = i-1; j >= 1; j--){
    //         if(numArr[i] > numArr[j] && memo[i] < memo[j]+ 1){ 
    //             memo[i] = memo[j] + 1; 
    //         }
    //     }
    // }
    for(int i = 1; i <= N; i++){
        memo[i] = 1;
        for(int j = 1; j < i; j++){
            if(numArr[i] > numArr[j] && memo[i] < memo[j]+ 1){ // 수열이 증가하고 + 이전 수열에서 시작하도록 하는게 더 좋을때
                memo[i] = memo[j] + 1;  // 메모 갱신
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