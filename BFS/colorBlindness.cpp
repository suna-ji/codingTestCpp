// 적록색약 - 10026
#include <iostream>
#include <queue>
#include <utility>
#define MAX 100
using namespace std;
int N;
char map[MAX][MAX];
int noVisit[MAX][MAX]; // 적록색약 아님
int yesVisit[MAX][MAX]; // 적록색약 맞음
queue<pair<int, int> > noQ;
queue<pair<int, int> > yesQ;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int areaCnt = 0;
void noBfs(int x, int y){
    noQ.push(make_pair(x, y));
    while(!noQ.empty()){
        x = noQ.front().first;
        y = noQ.front().second;
        noQ.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(noVisit[nx][ny]) continue;
            if(map[x][y] != map[nx][ny]) continue;
            noVisit[nx][ny] = 1;
            noQ.push(make_pair(nx, ny));
        }
    }
}
void yesBfs(int x, int y){
    yesQ.push(make_pair(x, y));
    while(!yesQ.empty()){
        x = yesQ.front().first;
        y = yesQ.front().second;
        yesQ.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(yesVisit[nx][ny]) continue;
            if((map[nx][ny] == 'B' || map[x][y] == 'B') && map[nx][ny] != map[x][y]) continue;
            yesVisit[nx][ny] = 1;
            yesQ.push(make_pair(nx, ny));
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    areaCnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!noVisit[i][j]){
                areaCnt++;
                noBfs(i, j);
            }
        }
    }
    cout << areaCnt << " ";
    areaCnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!yesVisit[i][j]){
                areaCnt++;
                yesBfs(i, j);
            }
        }
    }
    cout << areaCnt;
}
