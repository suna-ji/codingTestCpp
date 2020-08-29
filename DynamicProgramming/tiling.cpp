// 동적프로그래밍
// 1 큰 문제를 작은 문제로 나눌 수 있는가?
// 2 작은 문제에서 구한 정답이 그것을 포함하는 큰 문제에서도 동일하게 적용되는가?
// 2 x n 타일링 - 11726
// 점화식: D[n] = D[n-1]*1 + D[n-2]*1
#include <stdio.h>
#include <iostream>
using namespace std; 
int d[1001]; // n: 1~1000

int dp(int x){
    if(x == 1) return 1; // 재귀함수 종료 조건
    if(x == 2) return 2; // 재귀함수 종료 조건
    if(d[x]) return d[x]; // 이미 구한 값이면 그걸 이용(memoization)
    return d[x] = (dp(x-1) + dp(x-2)) % 10007;
}

int main(){
    int n;
    scanf("%d", &n); 
    cout << dp(n) << endl;
}


