// 파이프 옮기기2 - 17069
#include <iostream>
#define MAX 32 
using namespace std;
int gMemo[MAX][MAX];
int sMemo[MAX][MAX];
int dMemo[MAX][MAX]; 
// 가로 세로 대각
int map[MAX][MAX];
int N;
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }
    gMemo[1][2] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 2; j <= N; j++){
            if()
        }
    }
}
// 다음에..