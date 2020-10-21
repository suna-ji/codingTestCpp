// 특정한 최단 경로 -1504
// 출처: https://yabmoons.tistory.com/386
// 방향성이 없는 그래프
// 세준이는 1번에서 N번 정점으로 최단 거리로 이동하려고 한다.
// 1 -> spec1 -> spec2 -> N
// 1-> spec2 -> spec1 -> 1
// 두 가지 경우 존재
// 즉 1->spec1 // spec1->spec2 // spec1 -> N // spec2 -> N 각각을 구해야함
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 800 + 1
#define INF 999999999
using namespace std;
int N, E;
vector<pair<int, int> > v[MAX]; 
// v[출발지].first => 도착지
// v[출발지].second => 비용
int dist[MAX]; // dist[i] : i까지의 최소비용
int spec1, spec2; // 반드시 거쳐야 하는 두 정점

void distINF(){
    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }// 모든 정점에 대하여 dist INF로 초기화
}

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(0, start)); 
    while(!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        for(int i = 0; i < v[current].size(); i++){ // v[current] = {cost, destination}
            int next = v[current][i].first;
            int n_cost = v[current][i].second;
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
    cin >> N >> E;
    int a, b, c;

    for(int i = 1; i <= E; i++){
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
        // 방향성이 없는 그래프
    }
    cin >> spec1 >> spec2;
    // 입력끝
    bool flag1, flag2;
    flag1 = true;
    flag2 = true;
    distINF();
    dijkstra(1);
    int route1 = dist[spec1];
    int route2 = dist[spec2];
    if(route1 == INF) flag1 = false;
    if(route2 == INF) flag2 = false;
    // 첫번쨰 다익스트라 : 1 -> spec1 1 -> spec2
    distINF();
    dijkstra(spec1);
    int spec1ToN;
    if(flag1 == true){
        route1 += dist[spec2]; // 1 -> spec1 -> spec2
        spec1ToN = dist[N];
    } 
    if(flag2 == true) route2 += dist[spec2]; // 1 -> spec2 -> spec1 (// 1 -> spec2 + spec2 -> spec1)
    // 두번째 다익스트라 : spec1 -> spec2(무방향 그래프라서 spec2 -> spec1도 같음) ! 그래서 그냥 dist[spec2]해줘도 된다.
    distINF();
    dijkstra(spec2);
    if(flag1 == true) route1 += dist[N]; // 1 -> spec1 -> spec2 -> N (완성)
    // 세번째 다익스트라 : spec1 -> N
    if(flag2 == true) route2 += spec1ToN; // 1 -> spec2 -> spec1 -> N (완성)
    // 다익스트라 계산 끝
    int ans;
    if(flag1 == false && flag2 == false){
        ans = -1; 
    }else{
        ans = min(route1, route2);
    }
    if(ans == INF) ans = -1;
    cout << ans;
    // 출력
}