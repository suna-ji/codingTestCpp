// 동전2 - 2294
#include <iostream>
#include <algorithm>
#define CMAX 100 + 3
#define KMAX 10000 + 3
using namespace std;
// n가지 종류의 종전이 있다 -> 이 동전을 적절하게 사용해서 K원이 되도록 최소개수를 구해라
// 사용한 동전의 구성이 같은데 순서만 다른것은 같은 경우
// 혼자 풀었다!!
int n, k;
int coin[CMAX];
int memo[KMAX]; // memo[i]: i원을 만드는 동전의 최소 개수
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //빠른 입출력
    cin >> n;
    cin >> k;
    for(int i = 1; i <= n; i++){
        cin >> coin[i];
        if(coin[i] <= 10000){
            memo[coin[i]] = 1; // 동전과 동이란 k면 최소개수는 1
        }
    }
    // 셋중에 가장 최소값
    for(int i = 1; i <= k; i++){ // memo[k]를 구하기 위함
        if(memo[i] != 1){
            memo[i] = 999999999;
        }
        for(int j = 1; j <= n; j++){ // 모든 동전에 대한 경우 고려
            if(i - coin[j] >= 1){
                memo[i] = min(memo[i], memo[i-coin[j]] + 1);
            }
        }
    }
    if(memo[k] == 999999999){
        cout << -1;
    }else{
        cout << memo[k];
    }
}
// 불가능한 경우에는 -1을 출력한다. 

