// 2573 - 빙산
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAX 300
using namespace std;


int row, col; // 행, 열
int year;
int map[MAX][MAX];
int temp[MAX][MAX]; // 녹일때 이전 정보를 저장하기 위한 temp배열
bool visit[MAX][MAX];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
// 동 서 남 북

void dfs(int y, int x){
    visit[y][x] = true;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx >= 0 && ny >= 0 && nx < col && ny < row){
            if(map[ny][nx] && !visit[ny][nx]){
                dfs(ny, nx);
            }
        }
    }
}
void melt(){
    year++;
    for(int i = 0; i < row; i++){ //[x][]
        for(int j = 0; j < col; j++){ // [][y]
        int sum = 0;
            if(map[i][j]){ // 빙산이면
                int East = temp[i+1][j]; //동
                int West =  temp[i-1][j]; // 서
                int South =  temp[i][j+1]; // 남
                int North =  temp[i][j-1]; // 북
                if(East == 0) sum++;
                if(West == 0) sum++;
                if(South == 0) sum++;
                if(North == 0) sum++;
                if(map[i][j] - sum < 0){
                    map[i][j] = 0;
                }else{
                    map[i][j] -= sum;
                }
            }
        }
    }
    //변경된 map을 temp에 복사
}// 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 

// bool isMelt(){
//     bool isMelt = true;
//     for(int i = 0; i < row; i++){ 
//         for(int j = 0; j < col; j++){ 
//             if(map[i][j] != 0){
//                 isMelt = false;
//                 return isMelt;
//             }
//         }
//     }
//     return isMelt;
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d %d", &row, &col); // [x][] [][y]
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){ 
            cin >> map[i][j];
        }
    }
    while(1){
        memset(visit, false, sizeof(visit));
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){ 
                temp[i][j] = map[i][j];
            }
        }// 1. 녹이기전에 temp에 최신map 복사해줌
        melt(); //2. 녹인다. 
        //3. 녹은결과 분리되었는지 판단한다.
        int cnt = 0;
        
        for(int i = 0; i < row; i++){ // 행 x
            for(int j = 0; j < col; j++){ // 열 y
                if(map[i][j] && !visit[i][j]){
                    cnt++;
                    if(cnt > 1){
                        cout << year <<endl;
                        return 0;
                    }// 빙산이 분리 -> 년도 출력
                    dfs(i,j);
                }
            }
        }
        if(cnt == 0){
            year = 0;
            cout << year << endl;
            return 0;
        }
    }
    return 0;
}
// 실패 