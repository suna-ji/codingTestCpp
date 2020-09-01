// 그림 - 1926번
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 505
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int size = 0;
vector<int> dSize;
int map[MAX][MAX];
bool visit[MAX][MAX];
int n, m;

void dfs(int x, int y){
    visit[x][y] = true;
    size++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            if(map[nx][ny] && !visit[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);// 세로 가로
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    int dNum = 0;
    for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
           if(map[i][j] && !visit[i][j]){ // 색칠이 되어있고 방문안함
                dNum++;
                size = 0;
                dfs(i,j);
                dSize.push_back(size);
           }
       }
    }
    int largestSize;
    if(dNum == 0){
        largestSize = 0;
    }else{
        sort(dSize.begin(), dSize.end(), greater<int>()); //내림차순
        largestSize = dSize[0];
    }
    cout << dNum << endl; // 개수
    cout << largestSize << endl; // 제일 큰 사이즈
}