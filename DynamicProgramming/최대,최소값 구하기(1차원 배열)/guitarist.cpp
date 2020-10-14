// 기타리스트 - 1495
// 마지막 곡의 볼륨 중 최댓값을 출력
// 볼륨의 범위 0 <= volume <= M
#include <iostream>
#include <algorithm>
#define MAX 100 + 2
using namespace std;
int N, S, M; // N: 곡의 개수 S: 시작볼륨 M: 최대볼륨
int vArr[MAX];
int memo[MAX]; // memo[i] : i번째 곡을 연주할 때, 최대값
int main(){
    cin >> N >> S >> M;
    for(int i = 1; i <= N; i++){
        cin >> vArr[i];
    }
    int plusNextVolume;
    int minusNextVolume;
    memo[1] = S;
    for(int i = 1; i <= N; i++){
        plusNextVolume = memo[i] + vArr[i];
        minusNextVolume = memo[i] - vArr[i];
        if(plusNextVolume >= 0 && plusNextVolume <= M && minusNextVolume >=0 && minusNextVolume <= M){
            memo[i] = max(plusNextVolume, minusNextVolume);
        }else if(plusNextVolume >= 0 && plusNextVolume <= M){
            memo[i] = plusNextVolume;
        }else if(minusNextVolume >=0 && minusNextVolume <= M){
            memo[i] = minusNextVolume;
        }
        // 1 둘다 범위 만족
        // 2 pnv만 범위 만족
        // 3 mnv만 범위 만족
    }
    cout << memo[N];
}
// 이전 결과만 고려 -> 틀렸음
// 근데 다른 풀이 생각안나서 블로그 참조함