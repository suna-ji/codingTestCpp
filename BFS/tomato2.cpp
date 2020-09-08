// 토마토2 - 7569
#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int m, n, h;
int map[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int ans;
queue<pair<pair<int, int>, int> > q; 

void bfs(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
            if(dist[nz][nx][ny] >= 0 || map[nz][nx][ny] == -1) continue; 
            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push(make_pair(make_pair(nx, ny), nz));
        }
    }
}
void setAns(){
    ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(dist[i][j][k] == -1){
                    ans = -1;
                    return;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }
}
int main(){
    cin >> m >> n >> h; // m은 가로 -> y  n은 세로 -> x h는 높이
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> map[i][j][k];
                if(map[i][j][k] == 1){
                    q.push(make_pair(make_pair(j, k), i));
                }
                if(map[i][j][k] == 0){
                    dist[i][j][k] = -1;
                }
            }
        }
    }
    bfs();
    setAns();
    cout << ans << '\n';
}
