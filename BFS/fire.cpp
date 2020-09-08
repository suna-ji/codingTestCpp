// 불 - 4179
// 불에 대한 bfs를 먼저 돌려서 그 위치에 언제 불이 도착하는지 계산해두고
// 지훈이에 대한 bfs를 돌려서 그 위치일 때 불이 먼저 도착하거나 같이 도착했다면 패스하고
#include <queue>
#include <utility>
#include <iostream>
#include <cstring>
#define MAX 1000
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char map[MAX][MAX];
int R, C;
queue<pair<int, int> > q;
int fireDist[MAX][MAX]; // 방문표시 + 거리계산 한번에
int jihoonDist[MAX][MAX];
bool possible;
void fireBfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(fireDist[nx][ny] >= 0 || map[nx][ny] == '#') continue;
            fireDist[nx][ny] = fireDist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}
void jihoonBfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C){ // 탈출
                cout << jihoonDist[x][y] + 1 << "\n"; // 탈출하면서 1더해줌
                return;
            }
            if(jihoonDist[nx][ny] >= 0 || map[nx][ny] == '#') continue;
            if(fireDist[nx][ny] != -1 && fireDist[nx][ny] <= jihoonDist[x][y]+1) continue; // 불의 전파 시간을 조건에 추가
            jihoonDist[nx][ny] = jihoonDist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}
int main(){
    cin >> R >> C; // R이 x C가 y
    memset(fireDist, -1, sizeof(fireDist));
    memset(jihoonDist, -1, sizeof(jihoonDist));
    int jx, jy;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == 'J'){
                jx = i;
                jy = j;
                jihoonDist[i][j] = 0;
            }
            if(map[i][j] == 'F'){
                fireDist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    fireBfs();
    q.push(make_pair(jx, jy));
    jihoonBfs();
}

