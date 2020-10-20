// 최소비용 구하기2 - 11779
// PQ 참고!
// 최소비용과 그 경로를 출력
// Route[A] = B : A정점에 최소비용으로 도달하기 위해서는 b정점에서 와야한다.

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000 + 2
#define INF 999999999;
using namespace std;
int N; // 도시의 개수
int M; // 버스의 개수
int from, to;
int dist[MAX];

vector<pair<int, int> > V[MAX];
vector<int> Route_V;
priority_queue<pair<int, int> > PQ;

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }// dist(비용) 초기화

    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
    }//

    cin >> from >> to;
    PQ.push(make_pair(0, from)); 
    dist[from] = 0;
    while(PQ.empty() == 0){
        int Cost = -PQ.top().first; // 최소힙으로 구현하기 위함

        int Cur = PQ.top().second;
        PQ.pop();
        for(int i = 0; i < V[Cur].size(); i++){
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;

            if(Dist[Next] > Cost + nCost){
                Route[Next] = Cur;
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
    cout << Dist[End] << "\n";
    int Temp = End;


    
}