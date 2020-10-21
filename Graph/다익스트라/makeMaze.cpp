// 미로만들기 - 2665
// 출처: https://minerba93.tistory.com/18
#include <iostream>
#include <queue>
#include <utility>
#define MAX 50 + 2
#define INF 9999999
using namespace std;

int N; 
int map[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
priority_queue<pair<pair<int, int>, int> > pq; // x,y쌍과 비용


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &map[i][j]); // 연속된 숫자 한개씩 받기
            map[i][j] = !map[i][j]; // 우리는 최대한 흰방으로 가야함 근데 흰방이 1이고 검정이 0이니까 바꿔주자
            dist[i][j] = INF;
        }
    }
    // 입력완료!
    dist[0][0] = 0;
    pq.push(make_pair(make_pair(0, 0), 0)); 
    // 초기화
    while(!pq.empty()){
        int currentX = pq.top().first.first;
        int currentY = pq.top().first.second;
        int cost = -pq.top().second;
        pq.pop();
        //if(cost > dist[currentX][currentY]) continue;
        for(int i = 0; i < 4; i++){
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int n_cost = cost + map[nx][ny];
            if(n_cost < dist[nx][ny]){
                dist[nx][ny] = n_cost;
                pq.push(make_pair(make_pair(nx, ny), -n_cost));
            }
        }
    }
    // 다익스트라 연산
    printf("%d", dist[N-1][N-1]);
    return 0;
}