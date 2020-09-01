// DFS와 BFS - 1260번
// 단 방문할 수 있는 정점이 여러개인 경우에는 정점 번호가 작은 것을 먼저 방문
#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;
int N, M, V;
int map[MAX][MAX]; // bss영역 -> main으로 들어갈 때 0으로 초기화
bool visit[MAX];

void dfs(int v){
    visit[v] = true;
    cout << v << " ";
    for(int i = 1; i <=N; i++){
       if(map[v][i] && !visit[i]){
           dfs(i);
       }
    }
}
void bfs(int v){
    queue<int> q;
    q.push(v);
    visit[v] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int i = 1; i <= N; i++){
            if(map[v][i] && !visit[i]){
                visit[i] = true;
                q.push(i);
            }
        }
    }
}
int main(){
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        map[v1][v2] = 1;
        map[v2][v1] = 1;
    }
    dfs(V);
    memset(visit, 0, sizeof(visit));
    cout << endl;
    bfs(V);
}