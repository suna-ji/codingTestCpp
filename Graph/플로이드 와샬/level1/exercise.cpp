// 운동 - 1956
// V개의 마을 E개의 도로
// 도로는 마을과 마을 사이에 놓여 있음 일방 통행(방향)
// 도로를 따라 운동을 하기 위한 경로를 찾으려고 한다
// 도로의 합이 가장 작은 사이클을 찾아야한다 
// !두 마을을 왕복하는 경우도 사이클이다!
#include <iostream>
#define MAX 400 + 2
#define INF 1000000000
using namespace std;
int V, E;
int a, b, c; // a마을에서 b마을로 가는 거리가 c라는 뜻
int map[MAX][MAX];
int main(){
    cin >> V >> E;
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++){
            map[i][j] = INF;
        }
    }
    for(int i = 1; i <= E; i++){
        cin >> a >> b >> c;
        map[a][b] = c;
    }

    for(int k = 1; k <= V; k++){
        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    // 반복적으로 갱신하여 최종적으로 모든 최소 비용 구했음
     for(int k = 1; k <= V; k++){
        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    int ans = 99999999;
    int noCycle = true;
    for(int i = 1; i <= V; i++){
        if(ans > map[i][i]){
            ans = map[i][i];
            noCycle = false;
        }
    }
    // 사이클(map[i][i])
    if(noCycle){
        cout << -1;
    }else{
        cout << ans;
    }

}