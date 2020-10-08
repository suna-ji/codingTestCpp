// 2차원 배열의 합 - 2167
// 📝  굿노트에 필기해놨음 📝 
#include <iostream>
#define MAX 300 + 2
using namespace std;
int N, M;
int K;
int i, j, x, y;
int arr[MAX][MAX];
int memo[MAX][MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
            // 위에까지의 직사각형 + 왼쪽 직사각형 - 2번더한 정사각형  + 현재값
            memo[i][j] = memo[i-1][j] + memo[i][j-1] - memo[i-1][j-1] + arr[i][j];
        }
    }
    cin >> K;
    while(K--){
        cin >> i >> j >> x >> y;
        int result = memo[x][y] - memo[x][j-1] - memo[i-1][y] + memo[i-1][j-1];
        cout << result << "\n";
    }
} // dp적용 12ms (굿노트에 필기해놨음)

// 완전탐색 424ms
// int sum = 0;
// for(int a = x; a >= i; a--){
//     for(int b = y; b >= j; b--){
//         memo[a][b] = memo[a-x]
//     }
// }
// cout << sum << "\n";