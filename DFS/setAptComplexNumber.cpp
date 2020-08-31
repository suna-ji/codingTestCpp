// 단지번호 붙이기 - 2667(bfs로 분류되어있지만 dfs로 풀었음)
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 25
using namespace std;

int dx[] = {1, -1, 0 , 0};
int dy[] = {0, 0, 1, -1};
// 여기서 연결되었다는것은 어떤 집이 좌우, 혹은 아래위로 (대각선은 아님)
int N;
int cnt = 0;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<int> aptComplex;

void dfs(int x, int y){
    cnt++;
    visit[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny>= 0 && nx < N && ny < N){
            if(map[nx][ny] && !visit[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] && !visit[i][j]){ // 집이 있고 방문하지 않았다면
                cnt = 0;
                dfs(i,j);
                aptComplex.push_back(cnt);
            }
        }
    }
    sort(aptComplex.begin(), aptComplex.end()); // 오름차순으로 정렬
    cout << aptComplex.size() << endl;
    for(int i = 0; i < aptComplex.size(); i++){
        cout << aptComplex[i] << endl;
    }




}

