// 평범한 백팩 - 12865
#include <iostream>
#include <vector>
#include <utility>
#define MAX 100 + 2
using namespace std;
// 준서가 필요한 물건 N개
// 각 물건은 무게 W, 가치 V
// 준서는 최대 K무게까지의 배낭을 들 수 있다.
// 가치의 최대값 출력
// 보석도둑(그리디) 문제랑 비슷한듯..? -> 냅색문제를 그리디로 푼 경우
// DP문제중에서 유명한 냅색 문제라고 한다.
// 1 모든 경우를 다 세어본다.
// 2 넣을 수 있는 가장 비싼 물건부터 넣는다.
// 동적 계획법을 사용한다.
int N, K;
int memo[100001];
int w, v;
vector<pair<int, int> > stuffVec;
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> w >> v;
        stuffVec.push_back(make_pair(w, v));
    }
    for(int i = 0; i < N; i++){
        for(int j = K; j >= 1; j--){
            if(stuffVec[i].first <= j){
                memo[j] = max(memo[j], memo[j - stuffVec[i].first] + stuffVec[i].second);
            }
        }
    }
    cout << memo[K];
}