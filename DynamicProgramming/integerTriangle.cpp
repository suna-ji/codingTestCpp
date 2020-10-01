// 정수 삼각형 - 1932
#include <iostream>
#include <algorithm>
#define MAX 500+2
using namespace std;
int N;
int score[MAX][MAX];
int memo[MAX][MAX];

void getMaxSum(int n){
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(j == 1){
                memo[i][j] = memo[i-1][j] + score[i][j];
            } 
            else if(j == N){ // 제일 오른쪽
                memo[i][j] = memo[i-1][j-1] + score[i][j];
            }
            else{ // 가운데
                memo[i][j] = max(memo[i-1][j-1], memo[i-1][j]) + score[i][j];
            }
        }
    }
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> score[i][j];
        }
    }
    // 삼각형 점수 입력 받음
    memo[1][1] = score[1][1]; // 첫 번째 줄 
    getMaxSum(N);
    int maxSum = -99;
    for(int i = 1; i <= N; i++){
        maxSum = max(maxSum, memo[N][i]);
    }
    cout << maxSum;
}