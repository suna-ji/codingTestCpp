// 동전 - 2091
// X원짜리 커피를 사려 하는데, 이때 사용하는 동전의 개수를 최대
// 너무 어렵다
#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int X;
int A, B, C, D;
int maxCnt;
int ansA, ansB, ansC, ansD;
int memo[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> X >> A >> B >> C >> D;
    // 빠른 입출력
}
// 완전탐색 풀이
// dp는 어떻게 적용할지 생각해보자