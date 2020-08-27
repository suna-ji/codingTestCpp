//4963- 섬의 개수
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring> // memset
using namespace std;

int w, h; // dfs에서 boundary처리를 위해 전역으로 설정
int cnt = 0;
int map[50][50];
bool visit[50][50]; 
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

vector<int> answer; 

void dfs(int y, int x){
    visit[y][x] = true;
    for(int i = 0; i < 8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx >= 0 && ny >= 0 && nx < w && ny < h){
            if(map[ny][nx] && !visit[ny][nx]){
                dfs(ny, nx);
            }
        }
    }
}

int main(){
    while(true){
        scanf("%d %d", &w, &h);
        if(w == 0 && h ==0 ){
            break;
        }// 입력의 마지막에 00 들어옴
        memset(visit, false, sizeof(visit)); //visit초기화
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j< w; j++){
                cin >> map[i][j]; 
            }
        }// map입력받음
        cnt = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){ // 한줄씩 오른쪽으로 증가시키면서 dfs실행
                if(map[i][j] && !visit[i][j]){ // 땅이고 방문하지 않았으면
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }// while문 종료
  
    // for(int i = 0; i < answer.size(); i++){
    //     cout << answer[i] << endl;
    // }

}