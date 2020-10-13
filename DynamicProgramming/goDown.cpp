// 내려가기 - 2096
// 이동하기(11048)랑 비슷함
#include <iostream>
#include <algorithm>
#define MAX 100000 + 2
using namespace std;
int N;
int map[MAX][3];
int maxMemo[2][3];
int minMemo[2][3]; 

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
       maxMemo[1][0] = max(maxMemo[0][0], maxMemo[0][1]) + map[i][0];
       maxMemo[1][1] = max(max(maxMemo[0][0], maxMemo[0][1]), maxMemo[0][2]) + map[i][1];
       maxMemo[1][2] = max(maxMemo[0][1], maxMemo[0][2]) + map[i][2];
       
       minMemo[1][0] = min(minMemo[0][0], minMemo[0][1]) + map[i][0];
       minMemo[1][1] = min(min(minMemo[0][0], minMemo[0][1]), minMemo[0][2]) + map[i][1];
       minMemo[1][2] = min(minMemo[0][1], minMemo[0][2]) + map[i][2];

       maxMemo[0][0] = maxMemo[1][0];
       maxMemo[0][1] = maxMemo[1][1];
       maxMemo[0][2] = maxMemo[1][2];

       minMemo[0][0] = minMemo[1][0];
       minMemo[0][1] = minMemo[1][1];
       minMemo[0][2] = minMemo[1][2];
    }
    int minScore = 999999999;
    int maxScore = 0;
    for(int i = 0; i < 3; i++){
        maxScore = max(maxScore, maxMemo[0][i]);
        minScore = min(minScore, minMemo[0][i]);
    }
    cout << maxScore << " " << minScore;
}