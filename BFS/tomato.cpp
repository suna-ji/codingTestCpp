// 토마토 - 7576
#include <iostream>
#include <queue>
#include <utility> // make_pair
#define MAX 1000
using namespace std;

int board[MAX][MAX];
int dist[MAX][MAX];
queue<pair<int, int> > q;
int n, m;
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(){
    while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(dist[nx][ny] >= 0) continue; // 안익은 토마토만 dist -1로 해놨음
			dist[nx][ny] = dist[x][y] + 1;// 그 전 dist, 즉 몇일 지났는지에 +1 해줌
			q.push(make_pair(nx, ny)); 
		}
	}
}// bfs는 재귀가 필요없고 while문을 통해서 구현하는데 자꾸 헷갈리네?!

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n; // m은 y n은 x
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
			if(board[i][j] == 1){
				q.push(make_pair(i, j));
			}
			if(board[i][j] == 0){
				dist[i][j] = -1;
			}
		}
	}

    bfs();

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(dist[i][j] == -1){ // 아직도 안익은게 있으면
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]); // min max헤더는 algorithm
		}
	}
	cout << ans;
}