// 음식물 쓰레기 - 1743
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int dx[] = {0 , 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;
int cnt = 0;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<int> garbage;
// 상하좌우
void dfs(int x, int y){
    cnt++;
    visit[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > 0 && ny > 0 && nx <= n && ny <= m){//1부터 시작
            if(map[nx][ny] && !visit[nx][ny]){// 음식물쓰레기 이면서 방문 안함
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    int k;
    scanf("%d %d %d", &n, &m, &k); // 세로 가로 개수
    memset(map, 0, sizeof(map)); // map초기화
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        map[x][y] = 1; // 음식물
    }
    // 가장 큰 음식물 쓰레기의 크기를 출력
    //x고정하고 y증가시키면서 dfs실행
    for(int i = 1; i <= n; i++){ // 1부터 시작
        for(int j = 1; j <= m; j++){
            if(map[i][j] && !visit[i][j]){
                cnt = 0;
                dfs(i, j);
                garbage.push_back(cnt);
            }
        }
    }
    sort(garbage.begin(), garbage.end(), greater<int>());// 내림차순
    cout << garbage[0] << endl;
}