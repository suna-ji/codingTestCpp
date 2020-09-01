// 숨바꼭질 - 2697
#include <stdio.h>
#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

int N,K;
int visit[MAX];
int l = -1;
int r = 1;
int x;
int *dx[] = {&l, &r, &x};

void bfs(){
    queue<int> q;
    q.push(N);
    visit[N] = 1;
    while(!q.empty()){
        x = q.front(); // dx포인터 배열 갱신
        if(x == K){
            cout << visit[x] - 1 << endl;
            break;
        }
        q.pop();
        for(int i = 0; i < 3; i++){ // cur-1, cur+1, cur*2
            int nx = x + *dx[i];
            if(nx >= 0 && nx < MAX && !visit[nx]){ // 범위안에 있고 방문한 적 없다면
                q.push(nx);
                visit[nx] = visit[x] + 1;
            } 
        }

    }
}
int main(){
    scanf("%d %d", &N, &K);
    bfs();
}
