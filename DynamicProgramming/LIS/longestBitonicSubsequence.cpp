// 가장 긴 바이토닉 부분 수열 - 11054
// 수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이
// 가장 긴 증가하는 부분 수열 + 가장 긴 감소하는 부분 수열
#include <iostream>
#define MAX 1000 + 2
using namespace std;

int N;
int numArr[MAX];
int memo[MAX]; 
int r_memo[MAX]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    }
    // 증가!!
    for(int i = 1; i <= N; i++){
       memo[i] = 1; // 각각은 모두 1이니까
       for(int j = 1; j < i; j++){
           if(numArr[j] < numArr[i] && memo[i] < memo[j] + 1){ // 자기보다 이전에 있는 원소들 중 더 작은 원소 찾음 
               memo[i] = memo[j] + 1;
           }
       }
    }
    // 감소!!
    for(int i = N; i >= 1; i--){
        r_memo[i] = 1;
        for(int j = N; j > i; j--){
            if(numArr[i] > numArr[j] && r_memo[j] + 1 > r_memo[i]){
                r_memo[i] = r_memo[j] + 1;
            }
        }
    }
    // 답 출력
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, memo[i] + r_memo[i]);
    }
    cout << ans - 1; // 증가하다 감소하는 포인트! 그 숫자가 중복되어 계산된다 -> 1빼주기
}