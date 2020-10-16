// 플로이드 - 11404
// n개의 도시가 있다.
// 한 도시에서 시작하여 다른 도시에 도착하는 m개의 버스가 있다.
// 모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 최솟값을 구하시오
#include <iostream>
#define MAX 100 + 2
#define INF 1000000000
using namespace std;

int N, M;
int map[MAX][MAX];
int main(){
    cin >> N;
    cin >> M;
    int x, y, cost;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
        }
    }

    for(int i = 1; i <= M; i++){
        cin >> x >> y >> cost;
        if(map[x][y] > cost){
            map[x][y] = cost; 
        }
    }

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(map[i][j] == INF){
                map[i][j] = 0;
            }
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

}