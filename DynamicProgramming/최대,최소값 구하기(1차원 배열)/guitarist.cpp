// 기타리스트 - 1495
// 마지막 곡의 볼륨 중 최댓값을 출력
// 볼륨의 범위 0 <= volume <= M
#include <iostream>
#include <algorithm>
#define NMAX 100 + 2 // 곡의 개수
#define VMAX 1000 + 2 // 볼륨의 최대값
using namespace std;
int N, S, M; // N: 곡의 개수 S: 시작볼륨 M: 최대볼륨
int vArr[NMAX];
bool memo[NMAX][VMAX];  //memo[i][j] : i번째 곡을 연주할 때, j의 볼륨으로 연주할 수 있다 or 없다
int main(){
    cin >> N >> S >> M;
    for(int i = 1; i <= N; i++){
        cin >> vArr[i];
    }
    if(S + vArr[1] >= 0 && S + vArr[1] <= M) memo[1][S + vArr[1]] = true;
    if(S - vArr[1] >= 0 && S - vArr[1] <= M) memo[1][S - vArr[1]] = true;
    // 첫 곡에 대한 설정
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= M; j++){ // 해당 음량을 찾기 위한 반복문
            if(memo[i-1][j]){ // 전곡에서 j라는 음량으로 연주했다면!
                  if(j + vArr[i] >= 0 && j + vArr[i] <= M) memo[i][j + vArr[i]] = true;
                  if(j - vArr[i] >= 0 && j - vArr[i] <= M) memo[i][j - vArr[i]] = true;
            }// 이번곡에서 j에 더하거나 빼서 범위 확인하고 memoization
        }
    }
    // 2~N곡에 대해 계산
    bool noVolume = true;
    for(int i = M; i >= 0; i--){
        if(memo[N][i]){
            cout << i;
            noVolume = false;
            break;
        }
    }
    if(noVolume){
        cout << -1;
    }
}
