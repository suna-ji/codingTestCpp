// 연결 요소의 개수 - 11724
// dfs함수는 시작한 정점에서 갈 수 있는 모든 정점들을 방문한다.
// 즉, 같은 컴포넌트에 속한 점은 모두 방문
// 따라서. main에서 dfs()를 호출하는 횟수를 구하면 그게 연결요소 개수
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
// dfs는 그래프의 모든 정점을 검사하는 가장 단순하고 고전적인 방법
// 현재 정점과 인접한 간선들을 하나씩 검사하다가, 아직 방문하지 않은 간선이 있다면 그 간선을 따라간다.
// 이 과정에서 더 이상 갈곳이 없는 막힌 정점에 도달하면, 포기하고 마지막에 따라왔던 간선을 따라 뒤로 돌아감
// 출처: 알고리즘 문제 해결 전략2

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