// 계단 오르기 - 2579
// 답 나올때까지 변수 그냥 고쳐가며 풀어서 나중에 다시 풀어야함.
#include <iostream>
#include <algorithm>
#define MAX 300+2
using namespace std;
int N;
int score[MAX];
int memo[MAX];
void getMAXScore(int n){
    for(int i = 4; i <= N; i++){
        memo[i] = max((memo[i-2] + score[i]),(memo[i-3] + score[i-1] + score[i]));
    }
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> score[i];
    }
    memo[1] = score[1];
    memo[2] = score[1] + score[2];
    memo[3] = max((score[1] + score[3]), (score[2] + score[3]));
    getMAXScore(N);
    cout << memo[N];
}