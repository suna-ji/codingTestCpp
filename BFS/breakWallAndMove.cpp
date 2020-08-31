// 벽 부수고 이동하기 - 2206번
// 한 개의 벽을 부수고 이동하면 경로가 짧아 -> 벽을 한 개 까지 부수고 이동
// 0은 이동가능 1은 벽
#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
#define MAX 1001
using namespace std;

int N, M;
int map[MAX][MAX]; // 그냥 map
int cnt[MAX][MAX][2]; // 최단거리 계산과 방문여부를 확인을 위한 배열
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int bfs(){
    queue <pair<pair<int, int>, int> > q; // bfs구현을 위한 큐
    q.push(make_pair(make_pair(0, 0), 1));// 벽뚫기 가능 
    cnt[0][0][1] = 1;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int destroy = q.front().second;
        q.pop();
        if(x == N-1 && y == M - 1){
            return cnt[x][y][destroy]; // 도착했으면 최단거리 리턴
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                if(map[nx][ny] && destroy){ // 벽이 있고 벽을 부술 수 있는 상황
                    cnt[nx][ny][0] = cnt[x][y][destroy] + 1;
                    q.push(make_pair(make_pair(nx, ny), 0)); // 이제 부수는 기회 끝 -> 0
                }
                else if(!map[nx][ny] && cnt[nx][ny][destroy] == 0){ // 벽이 없고 방문하지 않았어
                    cnt[nx][ny][destroy] = cnt[x][y][destroy] + 1;
                    q.push(make_pair(make_pair(nx, ny), destroy));
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    cout << bfs() << endl;
}