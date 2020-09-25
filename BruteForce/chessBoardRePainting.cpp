// 체스판 다시 칠하기 - 1018
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// 아무곳에서나 8 * 8 크기의 체스판으로 자르고 다시 칠하면 된다
// 이떼 지민이가 다시 칠해야하는 정사각형의 최소 개수를 구해라
char map[50][50];
string whiteFirst[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string blackFirst[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",  
    "WBWBWBWB"
};

int compareWithWhiteFirst(int x, int y){
    int cnt = 0;
    for(int i  = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(map[x+i][y+j] != whiteFirst[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int compareWithBlackFirst(int x, int y){
    int cnt = 0;
    for(int i  = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(map[x+i][y+j] != blackFirst[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    int minCnt = 99999999;
    int newCnt;
    for(int i = 0; i < n-8+1; i++){
        for(int j = 0; j < m-8+1; j++){
            int a = compareWithBlackFirst(i, j);
            int b = compareWithWhiteFirst(i, j);
            newCnt = min(compareWithBlackFirst(i, j), compareWithWhiteFirst(i,j));
            minCnt = min(minCnt, newCnt);
                         // 흰색으로 시작하는 체스판과 비교   // 검정색으로 시작하는 체스판과 비교
        }
    }
    cout << minCnt;
}
