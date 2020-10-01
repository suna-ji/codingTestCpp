// 스티커 - 9465
#include <iostream>
#include <cstring>
#define MAX 100000 + 3
using namespace std;
int sticker[3][MAX];
int memo[3][MAX];
int T, N;
void func(){
   for(int i = 3; i <= N; i++){
       memo[1][i] = max(memo[2][i-1], memo[2][i-2]) + sticker[1][i];
       memo[2][i] = max(memo[1][i-1], memo[1][i-2]) + sticker[2][i];
   }
}
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        memset(memo, 0, sizeof(memo));
        for(int i = 1; i <= 2; i++){
            for(int j =1; j <= N; j++){
                cin >> sticker[i][j];
            }
        }
        // 입력완료
        memo[1][1] = sticker[1][1];
        memo[2][1] = sticker[2][1];
        memo[1][2] = sticker[2][1] + sticker[1][2];
        memo[2][2] = sticker[1][1] + sticker[2][2];
        func();
        cout << max(memo[1][N], memo[2][N]) << "\n";
    }
}