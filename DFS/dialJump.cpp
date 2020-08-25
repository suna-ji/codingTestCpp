// 숫자판 점프 -2210번
// dfs를 이용하여 완전탐색
#include <iostream>
#include <set>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
// 인접한 4곳
int map[5][5];
set<int> numbers; // 6자리 숫자(중복확인)

void dfs(int x, int y, int sum, int move){
    if(move == 5){ // 다섯번 이동
        numbers.insert(sum);
        return;
    }
    for(int i = 0; i <4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5){
            dfs(nx, ny, sum * 10 + map[nx][ny], move+1);
        }
    }
}

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            dfs(i,j,map[i][j], 0);
        }
    }
    
    cout << numbers.size() << endl;
}