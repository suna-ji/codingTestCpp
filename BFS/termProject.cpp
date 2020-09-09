// 텀 프로젝트 - 9466
#include <iostream>
#define MAX 100000
using namespace std;
// 팀 구성을 위해 함께하고 싶은 학생을 선택해야함
// 혼자 하고 싶은 경우 자기 자신을 선택
int T, n;
int map[MAX];
int dist[MAX];
queue<int> q;

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int nx = map[x];
        if(dist[nx] >= 0) continue;
        if(x == map[x]){
            cout << dist[x] << "\n";
            break;
        }
        dist[nx] = dist[x] + 1;
        q.push(nx);
    }
}

int main(){
    cin >> T; // 테스트 케이스 개수
    int pick;
    while(T--){
        cin >> n; // 학생 수
        bfs();
        for(int i = 1; i <= n; i++){
            cin >> pick;
            map[i] = pick;
            dist[i] = -1;
        }
    }
}
