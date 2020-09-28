// 촌수계산 - 2644
// 전형적인 BFS문제라고..한다..
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, node1, node2, m;
vector<int> graph[102]; // (1 ≤ n ≤ 100)
int dist[102];

int bfs(){
    queue<int> q;
    q.push(node1);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        if(current == node2){
            return dist[current];
        }
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i];
            if(!dist[next]){
                q.push(next);
                dist[next] = dist[current] + 1;
            }
        }
    }
    return -1;
}
int main(){
    cin >> n; // n: 전체사람의 수 
    cin >> node1 >> node2; // 촌수 계산할 2명
    cin >> m; // m: 부모 자식 관계의 개수
    int p, c;
    while(m--){
        cin >> p >> c;
        graph[p].push_back(c);
        graph[c].push_back(p);
    }
    cout << bfs() << "\n";
}