// 경로찾기 - 11403
// 가중치 없는 방향 그래프 G가 주어졌을 때, i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램
// 방법2. 플로이드 와샬
//---------------------------------방법2 플로이드 와샬------------------------------------------
#include <iostream>
#include <vector>
#define MAX 100 + 2
using namespace std;
int N;
int map[MAX][MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int isConnected;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
           cin >> map[i][j];
        }
    }
    
    for(int k = 1; k <= N; k++){
        // N: 거쳐가는 노드
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(map[i][k] == 1 && map[k][j]){
                    map[i][j] = 1;
                }
            }
        }
    }


    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
           cout << map[i][j] << " ";
        }
        cout << "\n";
    }

}
