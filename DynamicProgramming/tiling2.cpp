// 2 x n 타일링2 - 11727번
#include <iostream>
#include <stdio.h>
using namespace std;
// 점화식: D[n] = D[n -1] * 1 + D[n-2] * 2
int D[1001];
int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 3;
    if(D[x]) return D[x];
    return D[x] = (dp(x -1) + 2*dp(x-2)) % 10007;
}

int main(){
    int n;
    scanf("%d", &n);
    cout << dp(n) << endl;
}