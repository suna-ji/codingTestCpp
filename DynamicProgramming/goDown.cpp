// 내려가기 - 2096
// 이동하기(11048)랑 비슷함
#include <iostream>
#include <algorithm>
#define MAX 100000 + 2
using namespace std;
int N;
int map[MAX][3];
int maxMemo[MAX][3];
int minMemo[MAX][3]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> map[i][j];
        }
    }
    // 입력 완료
    for(int i = 0; i < 3; i++){
        maxMemo[0][i] = map[0][i];
        minMemo[0][i] = map[0][i];
    }
    for(int i = 1; i < N; i++){
       maxMemo[i][0] = max(maxMemo[i-1][0], maxMemo[i-1][1]) + map[i][0];
       maxMemo[i][1] = max(max(maxMemo[i-1][0], maxMemo[i-1][1]), maxMemo[i-1][2]) + map[i][1];
       maxMemo[i][2] = max(maxMemo[i-1][1], maxMemo[i-1][2]) + map[i][2];
       
       minMemo[i][0] = min(minMemo[i-1][0], minMemo[i-1][1]) + map[i][0];
       minMemo[i][1] = min(min(minMemo[i-1][0], minMemo[i-1][1]), minMemo[i-1][2]) + map[i][1];
       minMemo[i][2] = min(minMemo[i-1][1], minMemo[i-1][2]) + map[i][2];
    }
    int minScore = 99999;
    int maxScore = 0;
    for(int i = 0; i < 3; i++){
        maxScore = max(maxScore, maxMemo[N-1][i]);
        minScore = min(minScore, minMemo[N-1][i]);
    }
    cout << maxScore << " " << minScore;
}