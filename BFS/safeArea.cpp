// 안전영역 - 2468
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 100
using namespace std;
int N;
int map[MAX][MAX];
int maxRain = 0;
int areaSize = 0;
vector<int> ansVec; // 비 높이에 따른 안정영역의 크기 담아두는 벡터
queue<pair<int, int> > q;
bool visit[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int maxAreaNum = 0;

void bfs(int x, int y){
    q.push(make_pair(x, y));
    visit[x][y] = 1;
    while(!q.empty()){
        areaSize++;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(visit[nx][ny] || map[nx][ny] <= maxRain) continue; // 방문했거나 물에 잠겼으면 패스
            visit[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
}


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            maxRain = max(maxRain, map[i][j]);
        }
    }
    int cnt;
    maxRain++; 
    while(maxRain--){
        memset(visit, 0, sizeof(visit));
        cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visit[i][j] && map[i][j] > maxRain){
                    cnt++;
                    bfs(i,j);
                }
            }
        }
        maxAreaNum = max(cnt, maxAreaNum);
    }
    cout << maxAreaNum;
}