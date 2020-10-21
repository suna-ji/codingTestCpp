// 녹색 옷 입은 애가 젤다지? - 4485
// 미로만들기 - 2665랑 비슷함~!~!
// 녹색 옷 입은 링크는 [0][0] -> [N-1][N-1]까지 이동해야함
// 간 칸에는 도둑루피만 있는데 그 크기만큼 소지금을 잃게 된다.
// 잃는 금액을 최소로 하자 -> 작은것만 밟고 가자
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 125 + 2
#define INF 9999999
using namespace std;

int T;
int map[MAX][MAX];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int dist[MAX][MAX]; // 그래프는 도착점만 필요하지만 2차원 배열은 x,y 둘다 필요함

void distINF(){
    for(int i = 1; i <= T; i++){
        for(int j = 1; j <= T; j++){
            dist[i][j] = INF;
        }
    }
}
void dijkstra(){
    priority_queue<pair<pair<int, int>,int> > pq;
    dist[1][1] = map[1][1];
    pq.push(make_pair(make_pair(1, 1),-map[1][1])); // (0, 0)의 cost는 0
    while(!pq.empty()){
        int cx = pq.top().first.first;
        int cy = pq.top().first.second;
        int cost = -pq.top().second;
        pq.pop();
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int n_cost = cost + map[nx][ny];
            if(nx <= 0 || ny <= 0 || nx > T || ny > T) continue;
            if(dist[nx][ny] > n_cost){
                dist[nx][ny] = n_cost;
                pq.push(make_pair(make_pair(nx, ny), -n_cost));
            }
        }
    }
}
int main(){
    int cnt = 0;
    while(1){
        cnt++;
        cin >> T;
        if(T == 0){
            break;
        }
        for(int i = 1; i <= T; i++){
            for(int j = 1; j <= T; j++){
                cin >> map[i][j];
            }
        }
        distINF();
        dijkstra();
        cout << "Problem " <<cnt << ": " << dist[T][T] << "\n"; 
    }
}