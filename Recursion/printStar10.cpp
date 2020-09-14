// 별찍기 10 - 2447
// 재귀적인 패턴으로 별을 찍기
// N이 3의 거듭제곱이라고 할때, N * N 정사각형 모양이다.
#include <iostream>
using namespace std;
char map[2190][2190];

void func(int N, int x, int y){
    if(N == 1){
        map[x][y] = '*';
        return;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1){
                continue;
            }
            func(N / 3, x + N / 3 * i, y + N / 3 * j);
        }
    }
    
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map[i][j] = ' ';
        }
    }
    func(N, 0, 0);
    for(int i = 0; i < N; i++){
        cout << map[i] << "\n";
    }
}

