//영역 구하기 - 2583
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
// 직사각형 내부를 제회한 나머지 부분이 몇 개의 분리된 영역로 나눠지는지
// 즉 map[i][j] == 인거 찾아야함

int map[100][100];
bool visit[100][100];
int areaSize = 0;
int m, n, k;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void dfs(int x, int y){
    visit[x][y] = true;
    areaSize++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < m && ny < n){
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
                map[j][t] = 1;
            }
        }
    } // 직사각형의 갯수(k) 만큼 반복하면서 직사각형에 1로 표시
	vector<int> areaVec;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 0 && !visit[i][j]){
                areaSize = 0;  // 전역
                dfs(i, j);
                areaVec.push_back(areaSize);
            }
        }
    }// [0,0]~[m,n]까지 돌면서 dfs실행하고 그 결과로 나온 영역의 넓이를 벡터에 저장

	sort(areaVec.begin(), areaVec.end()); // 영역들 정렬
	cout << areaVec.size() << endl; // 출력
	for (int i = 0; i < areaVec.size(); i++) cout << areaVec[i] << " ";
}
