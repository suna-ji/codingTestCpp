// 이분 그래프 - 1707
// 인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 두 가지 색으로만 칠할 수 있는 그래프
// 즉, 그래프의 모든 정점이 두 그룹으로 나눠지고 서로 다른 그룹의 정점이 간선으로 연결되어져 있는 그래프를 말한다.
// 이분 그래프 판별은 BFS, DFS탐색을 이용!
// 서로 인접한 정점이 같은 색이라면 이분 그래프가 아님!! 
// 모든 정점을 방문하여 검사하기 때문에 시간 복잡도는 O(V + E)
#include <iostream>
#include <cstring>
#include <vector>
#define MAX 20000+3
using namespace std;
int v, e;
vector<int> graph[MAX];
int nodeColor[MAX];
// nodeColor 0 방문 x, 1, 2
void dfs(int node, int color){
    nodeColor[node] = color;
    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if(!nodeColor[next]){
            dfs(next, 3 - color); // 매개변수 1->2로, 2->1로
        }
    }
}
// 연결된 노드끼리 같은 색깔이면 0리턴
bool isBipartiteGraph(){
    for(int i = 1; i <= v; i++){ // v는 정점의 개수
        for(int j = 0; j < graph[i].size(); j++){ // 각 정점에 연결된 노드들을 돌면서
            int next = graph[i][j];
            if(nodeColor[i] == nodeColor[next]){ // 연결된 노드는 색깔이 달라야함 -> 같으면 false
                return false;
            }
        }
    }
    return true;
}
int main(){
    int t; // 테스트 케이스의 개수
    cin >> t;
    while(t--){
        cin >> v >> e;
        memset(nodeColor, 0, sizeof(nodeColor));
        memset(graph, 0, sizeof(graph));
        int n1, n2;
        while(e--){
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        for(int i = 0; i <= v; i++){
            if(!nodeColor[i]){
                dfs(i, 1);
            }
        }
        if(isBipartiteGraph()){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}