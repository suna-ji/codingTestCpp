// 회장뽑기 - 2660
// 회장을 선출하려고 한다.
// 회원사이에 서로 모르는 사람도 있지만, 몇 사람을 통하면 모두가 서로 알 수 있다.
// 각 회원은 다른 회원들과 가까울수록 점수 작음
// 점수가 가장 작은 사람이 회장 -> 회장의 점수 후보의 수 출력 -> 회장이 될 수 있는 모든 사람을 오름차순으로 출력
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 50 + 2
#define INF 99999999;
using namespace std;
int N; // 회원의 수
int a = 1;
int b = 1;
int map[MAX][MAX];
vector<pair<int, int> > scoreVec;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first){
        return p1.second < p2.second; // first가 동일하다면 second를 기준으로 오름차순 정렬
    }
    return p1.first < p2.first;// 우선 first 기준 오름차순으로 정렬
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
        }
    }
    while(1){
        cin >> a >> b;
        if(a != -1 && b != -1){
            map[a][b] = 1;
            map[b][a] = 1;
        }else{
            break;
        }
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
    int score;
    for(int i = 1; i <= N; i++){
        score = -999;
        for(int j = 1; j <= N; j++){
            if(i == j){
                continue;
            }else{
                score = max(score, map[i][j]);
            }
        }
        scoreVec.push_back(make_pair(score, i)); // 점수와 후보자 번호
    }

    sort(scoreVec.begin(), scoreVec.end(), compare);
    int index = N;
    for(int i = 0; i < N - 1; i++){
        if(scoreVec[i].first != scoreVec[i + 1].first){
            index = i+1;
            break; // 이거 빼먹어서 틀렸음!!
        }
    }
    cout << scoreVec[0].first << " " << index << "\n";
    for(int i = 0; i < index; i++){
        cout << scoreVec[i].second <<" ";
    }
}

