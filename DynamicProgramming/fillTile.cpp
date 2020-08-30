// 타일채우기 - 2133
#include <stdio.h>
#include <iostream>
using namespace std;
// 점화식: D[n] = D[n-2] * 3 + (D[n-4] * 2 + D[n-6] * 2 + ...+ D[0]*2)
// 4가 쪼개질 수 없기 때문에 6의 경우에 2->4인지 4->2인지에 따라 
//경우의 수 2개 나와서 이런 점화식인걸로 이해했는데 아닌것 같기도 하고

int D[31];
int dp(int x){
    if(x == 0) return 1;
    if(x == 1) return 0;
    if(x == 2) return 3;
    if(D[x]) return D[x];
    int result = 3 * dp(x-2);
    for(int i = 4; i <= x; i++){
        if(i % 2 == 0){ // 짝수면
            result += dp(x - i) * 2;
        }
    }
    return D[x] = result;
}
int main(){
    int n;
    scanf("%d", &n);
    cout << dp(n) << endl;
}