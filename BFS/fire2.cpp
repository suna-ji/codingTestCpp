// 불 - 5427
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define MAX 1002
using namespace std;

int w, h;
char map[MAX][MAX];
queue<pair<int, int> > fireQ; // 불 queue
queue<pair<int, int> > sgQ; // 상근이 quque
int fireDist[MAX][MAX]; // 불 Dist
int sgDist[MAX][MAX]; // 상근 Dist
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void fireBfs(){
    while(!fireQ.empty()){
        int x = fireQ.front().first;
        int y = fireQ.front().second;
        fireQ.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(map[nx][ny] == '#' || fireDist[nx][ny] >= 0) continue;
            fireDist[nx][ny] = fireDist[x][y] + 1;
            fireQ.push(make_pair(nx, ny));
        }
    }
}// 불 bfs

void sgBfs(){
    while(!sgQ.empty()){
        int x = sgQ.front().first;
        int y = sgQ.front().second;
        sgQ.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w){
                cout << sgDist[x][y] + 1 << "\n";
                return;
            }// 탈출
            if(map[nx][ny] == '#' || sgDist[nx][ny] >= 0) continue;
            if(fireDist[nx][ny] != -1 && sgDist[x][y] + 1 >= fireDist[nx][ny]) continue;
            // 상근이 1번더 움직였을 때 불이랑 만나거나 이미 불이 거기 있다면 continue; // 근데 주의할점은 fire가 계산된 상태여야함 즉 fire != -1
            sgDist[nx][ny] = sgDist[x][y] + 1;
            sgQ.push(make_pair(nx, ny));
        }
    }
    cout << "IMPOSSIBLE" <<"\n"; // 탈출못함

}// 상근이 bfs
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    int T;
    cin >> T;
    while(T--){
        cin >> w >> h;
        while(!sgQ.empty()){
            sgQ.pop();
        }
        while(!fireQ.empty()){
            fireQ.pop();
        }// 큐를 비워주지 않으면 문제가 생긴다.
        memset(map, 0, sizeof(map));
        memset(fireDist, -1, sizeof(fireDist)); // -1로 초기화 -> 나중에 최초 불의 위치만 0으로 
        memset(sgDist, -1, sizeof(sgDist)); // -1로 초기화 -> 나중에 최초 상근이 위치만 0으로 
        for(int i = 0; i < h; i++){ // h -> x
            for(int j = 0; j < w; j++){ // w -> y
                cin >> map[i][j];
                if(map[i][j] == '@'){
                    sgQ.push(make_pair(i, j));
                    sgDist[i][j] = 0;
                }// 상근이 위치
                if(map[i][j] == '*'){
                    fireQ.push(make_pair(i, j));
                    fireDist[i][j] = 0;
                }// 불 위치
            }
        }
        fireBfs();
        sgBfs();
    }
}