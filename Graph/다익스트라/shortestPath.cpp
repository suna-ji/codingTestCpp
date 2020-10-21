// 최단경로 - 1753
// 방향 그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하세요.
// 시작점 자신은 0으로 출력, 경로가 존재하지 않는 경우는 INF출력
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 999999999
#define MAX 20000 + 2
using namespace std;
int V, E, K;//  정점의 개수, 간선의 개수, 시작 정점의 번호
vector<pair<int, int> > vec[MAX];
// V[i].first = 도착지
// V[i].first = 비용
int dist[MAX];// 정점까지의 총 비용

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    // first 총비용  second 도착점
    dist[start] = 0;
    pq.push(make_pair(0, start));
    // 시작점 초기화
    while(!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        for(int i = 0; i < vec[current].size(); i++){
            int next = vec[current][i].first;
            int n_cost = vec[current][i].second;
            if(dist[next] > cost + n_cost){
                dist[next] = cost + n_cost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> V >> E;
    cin >> K;
    int u, v, w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        vec[u].push_back(make_pair(v, w));
    }
    // 입력끝
    for(int i = 1; i <= V; i++){
        dist[i] = INF;
    }
    dijkstra(K);
    // 다익스트라 연산
    for(int i = 1; i <= V; i++){
        if(i == K){
            cout << 0 << "\n";
        }else{
            if(dist[i] == INF){
                cout << "INF" << "\n";
            }else{
                cout << dist[i] << "\n";
            }
        }
    }
    // 출력
}