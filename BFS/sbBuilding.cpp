// 상범 빌딩 - 6539
// 탈출하는 가장 빠른 길은 무엇일까? -> BFS
// 각 칸에서 인접한 6개의 칸(동 서 남 북 상 하)으로 1분의 시간을 들여 이동할 수 있다.
#include <stdio.h>
#include <iostream>
#define MAX 31
using namespace std;

int L, R, C; // 층 행 열
char map[MAX][MAX];

void bfs(int x, int y){
    queue<pair<int, int> > q; // x,y는 좌표 -> int, int
    q.push(make_pair(x,y));
    visit[x][y] = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(map[x][y] == 'E'){
           printf("Escaped in %d minute(s).", visit[x][y]);
           break;
        }
        for(int i = 0; i < 6; i++)[

        ]
    }


}

int main(){
    while(1){
        scanf("%d %d %d", &L, &R, &C);
        if(!L && !R && !C){
            break;
        }
        while(L--){
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    scanf("%c", &map[i][j]);
                }
            }
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    if(map[i][j] == 'S'){
                        bfs(i,j);
                    }
                }
            }
            bfs();
        }
    }
}
// 쉬운거 먼저 하고 다시