// 부녀회장이 될테야 - 2775
// a층 b호는 (a-1)층 1호부터 b호까지의 인원수 합이 되어야한다.
// 0층부터 존재함
// 점화식: memo[k][n] = memo[k-1][n] + memo[k][n-1]
#include <iostream>
#define MAX 14 + 1
using namespace std;
int T;
int k, n;
int memo[MAX][MAX];
int main(){
    cin >> T;
    for(int i = 1; i <= 14; i++){
        memo[0][i] = i;
    } // 0층 계산
    for(int i = 1; i <= 14; i++){
        for(int j = 1; j <= 14; j++){
            memo[i][j] = memo[i-1][j] + memo[i][j-1];
        }
    }
    while(T--){
        cin >> k;
        cin >> n;
        cout << memo[k][n] << "\n";
    } 
}