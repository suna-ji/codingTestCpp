// 기타리스트 - 1495
// 마지막 곡의 볼륨 중 최댓값을 출력
// 볼륨의 범위 0 <= volume <= M
#include <iostream>
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
    for(int i = 1; i <= N; i++){

    }

}