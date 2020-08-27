//2583-영역 구하기
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;



int map[100][100];
bool visit[100][100];
int cnt = 0;
int m, n, k;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void dfs(int x, int y){
    visit[x][y] = true;
    cnt++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            if(map[nx][ny] == 0 && !visit[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}



int main() {
	scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++){
        int lx, ly, rx, ry;
        scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
        for(int j = ly; j < ry; j++){
            for(int t = lx; t < rx; t++){
                visit[j][t] = true;
                map[j][t] = 1;
            }
        }
    } // 직사각형의 갯수(k) 만큼 반복하면서 직사각형에 1로 표시
	vector<int> areaVec;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 0 && !visit[i][j]){
                cnt = 0;  // 전역
                dfs(i, j);
                areaVec.push_back(cnt);
            }
        }
    }// [0,0]~[m,n]까지 돌면서 dfs실행하고 그 결과로 나온 영역의 넓이를 벡터에 저장

	sort(areaVec.begin(), areaVec.end()); // 영역들 정렬
	cout << areaVec.size() << endl; // 출력
	for (int i = 0; i < areaVec.size(); i++) cout << areaVec[i] << " ";
	return 0;
}

// 테스트케이스
// 5 7 3
// 0 2 4 4
// 1 1 2 5
// 4 0 6 2
