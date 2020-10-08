// 2차원 배열의 합
#include <iostream>
#define MAX 300 + 2
using namespace std;
int N, M;
int K;
int i, j, x, y;
int arr[MAX][MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
        }
    }
    cin >> K;
    while(K--){
        cin >> i >> j >> x >> y;
        int sum = 0;
        for(int a = i; a <= x; a++){
            for(int b = j; b <= y; b++){
                sum += arr[a][b];
            }
        }
        cout << sum << "\n";
    }
}