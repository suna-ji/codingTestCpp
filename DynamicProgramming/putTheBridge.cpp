// 다리 놓기 - 1010
#include <iostream>
#define MAX 30 + 2
#include <cstring>
using namespace std;
// 각 다리는 겹쳐서는 안된다. -> 즉 양쪾의 정점은 항상 순서대로 연결!
// 그럼 동쪽의 M개의 사이트 중 N를 뽑아서 그냥 순서대로 연결하기만 하면 된다 
// 즉 M개 중 N개 뽑는 문제!
int T;
int N, M;
int memo[MAX][MAX];
int func(int n, int r){ // nCr
    if(n == r || r == 0){
        return 1;
    }// n개에서 n개 뽑는 경우의 수 1이고 0개 뽑는 경우의 수도 1이다.
    if(memo[m][n]) return memo[m][n]; // 이미 구했다면 리턴
    return memo[m][n] = func(m-1, n-1) + func(m-1, n); // 
}
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        memset(memo, 0, sizeof(memo));
        cout << func(M, N) << "\n"; // M개중에 N개 뽑음
    }
}