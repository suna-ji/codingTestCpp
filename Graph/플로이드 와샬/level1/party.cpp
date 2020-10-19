// 파티 - 1238
// 플로이드 와샬로 풀었음
#include <iostream>
#include <algorithm>
#define MAX 1000 + 2
#define INF 999999999;
using namespace std;
// N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고있다.
// N명의 학생이 X마을에 모여서 파티를 하기로 했다.
// 이 마을에는 M개의 다리가 있다(단방향)
// i번째 길을 지나는데 T시간을 소비한다. //
// 학생들 중 오고가는데 가장 많은 시간을 소비하는 학생은 누구인가?! (다들 최단시간으로 가는데 그 중 가장 시간 많이 걸리는 친구)
int N, M, X;
int map[MAX][MAX];
int main(){
    cin >> N >> M >> X;
    int a, b, c;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if (i == j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
        }
    }
    for(int i = 1; i <= M; i++){
        cin >> a >> b >> c;
        map[a][b] = c;
    }
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j){
                    continue;
                }
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    int maxAns = -9999;
    for(int i = 1; i <= N; i++){
        maxAns = max(maxAns, map[i][X] + map[X][i]);
    }
    cout << maxAns;
}