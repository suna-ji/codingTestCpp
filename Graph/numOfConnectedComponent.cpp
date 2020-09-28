//  연결 요소의 개수 - 11724
#include <iostream>
#include <vector>
using namespace std;
int n, m; // n : 정점의 개수 m : 간선의 개수
int cnt = 0; // 연결요소의 개수
vector<int> graph[1002];
bool visit[1002];

void dfs(int node){
    visit[node] = 1;
    for(int i = 0; i < graph[node].size(); i++){
        int nextNode = graph[node][i];
        if(!visit[nextNode]){
            dfs(nextNode);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 방향이 없는 그래프 -> 모두 넣어준다.
    }
    for(int i = 1; i <= n; i++){ // for문 1개만 돌린다 1->n까지의 정점에 대한 반복문이니까
        if(!visit[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}