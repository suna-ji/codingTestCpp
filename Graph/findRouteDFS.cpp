// 경로찾기 - 11403
// 가중치 없는 방향 그래프 G가 주어졌을 때, i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램
// 방법1. DFS
//---------------------------------방법1 DFS------------------------------------------
#include <iostream>
#include <vector>
#define MAX 100 + 2
using namespace std;
int N;
int map[MAX][MAX];
bool visit[MAX][MAX];

void dfs(int x, int y){
    map[x][y] = 1;
    visit[x][y] = true;
    for(int i = 1; i <= N; i++){
        if(!visit[x][i] && map[y][i] == 1){
            cout << "x" << x <<"/" <<"i" << i << "/" << "y" << y <<"\n";
            dfs(x, i);
        } 
        //x에서 방문안한 i중에서 y에서 시작하여 갈 수 있는 지점이 있다면 
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int isConnected;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
           cin >> map[i][j];
        }
    }
    // 그래프 G 입력 완료
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(!visit[i][i] && map[i][j] == 1){
                dfs(i, j);
            }
        }
    }// 모든 정점이 간선을 통해 이어졌다는 보장이 없음 ->모든 정점에 대해 순서대로 dfs호출 필요
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
           cout << map[i][j] << " ";
        }
        cout << "\n";
    }

}

