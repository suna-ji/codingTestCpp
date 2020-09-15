// 별찍기 11 - 2448
#include <iostream>
using namespace std;
char map[3100][6600];

void func(int N, int x, int y){
    if(N == 3){
        map[x][y] = '*';
		map[x + 1][y-1] = '*'; map[x + 1][y+1] = '*';
		for (int i = 0; i < 5; i++) map[x + 2][y + i-2] = '*';
        return;
    }
    func(N / 2, x, y); // 첫번째 삼각형
    func(N / 2, x+N/2 , y - N/2); // 2번째 삼각형 
    func(N / 2, x+N/2, y + N/2); // 3번째 삼각형
}
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N * 2 - 1; j++){
            map[i][j] = ' ';
        }
    }
    func(N, 0, N-1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N * 2 - 1; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}
