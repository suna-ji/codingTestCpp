// 결혼식 - 5567
#include <iostream>
#include <vector> 
#include <queue>
#define MAX 500
using namespace std;
int n, m; // 정점의 개수(상근이 친구)
vector<int> graph[MAX];
int dist[MAX];
int cnt;
void bfs(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i = 0; i < graph[current].size(); i++){
            int next = graph[current][i];
            if(!dist[next] && dist[current] < 2){
                q.push(next);
                cnt++;
                dist[next] = dist[current] + 1;
            }
        }
    }
}
// void cntFriends(){
//     cnt = 0;
//     for(int i = 2; i <= n; i++){
//         if(dist[i] == 1 || dist[i] == 2){ // 친구거나 친구의 친구거나
//             cnt++;
//         }
//     }
// }
int main(){
    cin >> n;
    cin >> m; // 리스트의 길이
    int a, b;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cnt = 0;
    bfs();
    //cntFriends();
    cout << cnt-1  << "\n"; // 본인 제외
}