#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 1000 + 2 //도시의 개수는 1이상 1000이하
#define INF 99999999
using namespace std;

int N, M; // 도시 버스
int start, stop; // 출발지 도착지
vector<pair<int, int> > v[MAX]; // 도착지와 비용쌍을 갖는 벡터배열
int dist[MAX]; // dist[i] : i까지의 최소비용
int route[MAX];
vector<int> reversed_route;
priority_queue<pair<int, int> > pq; // pq에서 하나씩 꺼내면서 계산할거다! COST와 정점정보둘다 필요! 
int main(){
    ios:: sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> N >> M;
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    cin >> start >> stop;
    // 입력완료!
    for(int i  = 1; i <= N; i++){ // 모든 도시에 대해서 최소비용 INF로 초기화
        dist[i] = INF;
    }
    pq.push(make_pair(0, start));
    dist[start] = 0;
    // 초기화
    while(!pq.empty()){
        int cost = -pq.top().first; // 최소힙 구현 (가장 비용 적은거 구해야 하니까)
        int current = pq.top().second;
        pq.pop();
        for(int i = 0; i < v[current].size(); i++){
            int next = v[current][i].first;
            int nextCost = v[current][i].second;
            if(dist[next] > cost + nextCost){
                dist[next] = cost + nextCost;
                route[next] = current;
                pq.push(make_pair(-dist[next], next)); // 넣을 때, -붙여야 최소힙 구현가능
            }
        }
    }
    cout << dist[stop] << "\n";
    // 경로 역추적
    int temp = stop;
    while(temp){
        reversed_route.push_back(temp);
        temp = route[temp];
    }
    cout << reversed_route.size() << "\n";
    for(int i = reversed_route.size()-1; i >= 0; i--){
        cout << reversed_route[i] << " ";
    }
}