// 민준이와 마산 그리고 건우 - 18223
// 직접 지도를 보고 가장 짧은 길을 찾으려고 한다,
// 지도는 양방향
// 출발지는 1번정점 마산은 V정점
// 건우는 P번에 있다
// 민준이가 건우를 도와주는 경로의 길이가 최단 경로보다 길지 않다면 민준이는 건우 도와준다.
// 민준이가 찾은 최단 경로위에 건우가 있다면 "SAVE HIM" 아니면 "GOOD BYE"출력
// start를 1로 두고 다익스트라 돌려서 dist[V] 랑 dist[p] 구하고.
// start를 p로 두고 다익스트라 돌려서 dist[V]구해서 
// dist[V] >= dist[p] + dist[V]
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 5000 + 2
#define INF 999999999
using namespace std;
int V, E, P;
vector<pair<int, int> > vec[MAX];
int dist[MAX];

void distINF(){
    for(int i = 1; i <= V; i++){
        dist[i] = INF;
    }
}

void dijkstra(int start){
    priority_queue<pair<int, int> > pq; // 도착지와 길이 담아야함
    dist[start] = 0;
    pq.push(make_pair(0, start));
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
    cin >> V >> E >> P;
    int a, b, c;
    for(int i = 1; i <= E; i++){
        cin >> a >> b >> c;
        vec[a].push_back(make_pair(b, c));
        vec[b].push_back(make_pair(a, c));
    }
    distINF();
    dijkstra(1);
    int oneToV = dist[V];
    int oneToP = dist[P];
    distINF();
    dijkstra(P);
    int PtoV = dist[V];
    if(oneToV >= oneToP + PtoV){
        cout << "SAVE HIM" << "\n";
    }else{
        cout << "GOOD BYE" << "\n";
    }
}
