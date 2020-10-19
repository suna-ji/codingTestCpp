// 케빈 베이컨의 6단계 법칙 - 1389
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 100 + 2
#define INF 1000000
using namespace std;
// 임의의 두 사람이 최소 몇 단계 만에 이어질 수 있는지 계산하는 게임
// 단계의 총 합을 케빈 베이컨이라고 한다. 
// 케빈 베이컨 수가 가장 적은 사람을 찾아라
int N, M; // 인원, 친구관계 수
int map[MAX][MAX];
vector<pair<int, int> > kevinBaconVec;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first){
        return p1.second < p2.second; // first가 동일하다면 second를 기준으로 오름차순 정렬
    }
    return p1.first < p2.first;// 우선 first 기준 오름차순으로 정렬
};
//  케빈 베이컨의 수가 가장 작은 사람을 출력한다. 그런 사람이 여러 명일 경우에는 번호가 가장 작은 사람을 출력한다.

int main(){
    cin >> N >> M;
    int a, b;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
           map[i][j] = INF;
        }
    }
    // INF로 초기화
    for(int i = 1; i <= M; i++){
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    // 직접적인 관계가 있다면 1로 넣어줌
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    int sum;
    
    for(int i = 1; i <= N; i++){
        sum = 0;
        for(int j = 1; j <= N; j++){
           sum += map[i][j];
        }
        kevinBaconVec.push_back(make_pair(sum, i));
    }
    sort(kevinBaconVec.begin(), kevinBaconVec.end(), compare);
    cout << kevinBaconVec[0].second;
}