// 전깃줄 - 2565
// 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때,
// 교차하지 않도록 없애야 하는 전깃줄의 최소 개수를 구하라
// 실버1이라니..? 
// A전봇대 기준으로 정렬하고
// LIS문제처럼 풀고
// 전체길이에서 LIS값 빼면 된다!
#include <iostream>
#include <vector>
#include <utility> // pair
#include <algorithm>
#define MAX 500 + 2
using namespace std;
int N;
int memo[MAX];
vector<pair<int, int> > electricVec;
int main(){
    cin >> N;
    int poleA, poleB; 
    for(int i = 0; i < N; i++){
        cin >> poleA >> poleB;
        electricVec.push_back(make_pair(poleA, poleB));
    }
    sort(electricVec.begin(), electricVec.end());
    // A전봇대 기준으로 정렬
    // 이때, B전봇대는 증가하는 수열이 되어야 겹치지 않는다.
    // 없애야 하는 전깃줄의 최소 개수 == 가장 긴 증가하는 부분 수열
    for(int i = 0; i < N; i++){
        memo[i] = 1; // 일단 자기 자신의 길이1은 보장
        for(int j = 0; j < i; j++){
            if(electricVec[j].second < electricVec[i].second && memo[i] < memo[j] + 1){
                memo[i] = memo[j] + 1;
            }
        }
    }
    int lcs = 0;
    for(int i = 0; i < N; i++){
        lcs = max(lcs, memo[i]);
    }
    int ans = N - lcs;
    cout << ans;
}