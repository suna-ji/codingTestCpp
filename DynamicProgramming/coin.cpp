// 동전 - 2091
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
    // 빠른 입출력
    cin >> X >> A >> B >> C >> D;
    memo[1] = 1;

    maxCnt = -99;
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            for(int k = 0; k <= C; k++){
                for(int l = 0; l <= D; l++){
                    if(X == 1*i + 5*j + 10 *k + 25 * l){
                        int newCnt = i + j + k + l;
                        if(maxCnt < newCnt){
                            maxCnt = newCnt;
                            ansA = i;
                            ansB = j;
                            ansC = k;
                            ansD = l;
                        }
                    }
                }
            }
        }
    }
    cout << ansA <<" "<< ansB <<" "<< ansC <<" "<< ansD;
}
// 완전탐색 풀이
// dp는 어떻게 적용할지 생각해보자