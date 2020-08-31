// 미로탐색 - 2178번
// 최단거리 -> BFS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
#define MAX 100
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
// 상 하 좌 우
int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];

void bfs(int x, int y){
    queue<pair<int, int> > q;
    queue<int> cnt;
    cnt.push(1);
    q.push(make_pair(x,y));
    visit[x][y] = 1;
    while(q.size()){
        x = q.front().first;
        y = q.front().second;
        int c = cnt.front(); 
        q.pop();
        cnt.pop();
        if(x == N-1 && y == M-1){
            cout << c << endl;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                if(map[nx][ny] == 1 && !visit[nx][ny]){
                    q.push(make_pair(nx, ny));
                    visit[nx][ny] = 1;
                    cnt.push(c+1);
                } 
            }
        }

    }
}

int main(){
    scanf("%d %d",&N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &map[i][j]); // 연속된 숫자를 하나씩 분리해서 받기
        }
    }
    bfs(0, 0);
}