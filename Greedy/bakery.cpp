// 빵집- 3109번
#include <stdio.h>
#include <iostream>
using namespace std;

char map[10001][500];
bool visit[10001][500];
bool ans;
int r,c,sum;

int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
// 대각선 위, 오른쪽, 대각선 아래

void dfs(int x, int y){
    visit[x][y] = true;
    if(y == c - 1){ // 마지막 열(원웅이 빵집)
        ans = true;
        sum++;
        return; // 종료
    }
    for(int i = 0; i < 3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i]; // 대각선 위, 오른쪽, 대각선 아래 방문
        if(nx >= 0 && ny >=0 && nx < r && ny < c){
            if(map[nx][ny] == '.' && visit[nx][ny] == false){
                dfs(nx,ny);
                if(ans == true) return;
            }
        }
    }
}

int main(){
    scanf("%d %d", &r, &c);
    getchar();
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%c", &map[i][j]);
        }
        getchar();
    }

    for(int i = 0; i < r; i++){
        ans = false;
        dfs(i, 0);
    }
    cout << sum << endl;
}