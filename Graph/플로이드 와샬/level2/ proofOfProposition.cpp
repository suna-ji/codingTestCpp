// 명제 증명 - 2224
// P=>Q, Q=>R 이면 P=>R 
// P=>P 와 같이 전건과 후건이 같은 경우는 출력하지 않는다.
// N개의 참인 명제가 주어졌을 때, 증명될 수 있는 명제를 모두 출력하라
#include <iostream>
// 공백기준 문자열 자르기 위한 헤더
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 52 // 알파벳 소문자 대문자
using namespace std;
int N;
int map[MAX+1][MAX+1];
vector<pair<int, int> > ans;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first){
        return p1.second < p2.second; // first가 동일하다면 second를 기준으로 오름차순 정렬
    }
    return p1.first < p2.first;// 우선 first 기준 오름차순으로 정렬
};

int minusFunc(int n){ 
    if(n >= 65 && n <= 90){ // 대문자
        n -= 64;
    }else{ // 소문자
        n -= 70;
    }
    return n;
}
int plusFunc(int n){
    if(n >= 1 && n <= 26){ // 대문자
        n += 64;
    }else{ // 소문자
        n += 70;
    }
    return n;
}

int main(){
    ios::sync_with_stdio(0);
    //cin.tie(0);
    // 빠른 입출력
    cin >> N;
    cin.ignore();
    char proposition[10]; //명제가 문자열로 주어짐
    for(int i = 1; i <= N; i++){
        cin.getline(proposition, 10); // 공백포함해서 명제 입력받고
        int a = minusFunc((int)proposition[0]); // 가정
        int b = minusFunc((int)proposition[5]); // 결론
        if(a == b){
            map[a][b] = 0;
        }else{
            map[a][b] = 1;
        }
    }
    for(int k = 1; k <= MAX; k++){
        for(int i = 1; i <= MAX; i++){
            for(int j = 1; j <= MAX; j++){
                if(i == j){
                    continue;
                }
                if(map[i][k] == 1 && map[k][j] == 1){
                    map[i][j] = 1;
                }
            }
        }
    }
    for(int i = 1; i <= MAX; i++){
        for(int j = 1; j <= MAX; j++){
            if(map[i][j] == 1){
                ans.push_back(make_pair(i, j));
            }
        }
    }

    sort(ans.begin(), ans.end(), compare);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << char(plusFunc(ans[i].first)) << " => " << char(plusFunc(ans[i].second))<< "\n";
    }
}