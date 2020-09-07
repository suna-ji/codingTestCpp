// 그림 - 1926
// bfs로 풀어보자
#include <iostream>
#include <queue>
#include <utility> // pair
#include <algorithm>
#define MAX 500
using namespace std;

int map[MAX][MAX];
int visit[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m; // 가로 세로
int dNum = 0; // 그림의 개수
int area = 0;
vector<int> dVec; // 그림의 사이즈를 담을 벡터
queue<pair<int, int> > q; // bfs를 구현하기 위한 큐

void bfs(int x, int y){
    area = 0;
    q.push(make_pair(x, y));
    visit[x][y] = 1;
    while(q.size()){
        area++;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                if(!visit[nx][ny] && map[nx][ny]){ // 방문하지 않았고 그림이라면
                    q.push(make_pair(nx, ny));
                    visit[nx][ny] = 1;
                }
            }
        }
    }
    
} 
int main(){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visit[i][j] && map[i][j]){
                bfs(i, j);
                dVec.push_back(area);
                dNum++;
            }
        }
    }
    sort(dVec.begin(), dVec.end(), greater<int>());
    cout << dNum << "\n";
    if(dVec.size() == 0){
        cout << 0 << "\n";
    }else{
         cout << dVec[0] << "\n";
    }
}
// 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력