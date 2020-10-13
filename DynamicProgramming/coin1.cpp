// 동전 1 - 2293
// 사용한 동전의 구성은 같은데 순서만 다른것은 같은 경우이다
// 출처 :  https://yabmoons.tistory.com/491 [얍문's Coding World..]
// 다시!!
#include <iostream>
#define CMAX 100 + 4
#define KMAX 10000 + 4
using namespace std;

int N, K;
int coin[CMAX];
int memo[KMAX];
int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> coin[i];
    }

    memo[0] = 1;
    // memo[i] : i원을 만들 수 있는 경우의 수
    for(int i = 1; i <= N; i++){ // coin[i]
        for(int j = coin[i]; j <= K; j++){ // coin[i]로 만들 수 있는 최소비용 coin[i]~k까지
            //cout << "memo[" << j<<"] = memo["<<j<< "] + memo["<<j<<" - coin["<<i<<"]" << "\n";
            memo[j] = memo[j] + memo[j - coin[i]];
            // 동전 coin[i]를 이용해서 j원을 만들고 싶다.
        }
    }
  
    // coin = {1, 2, 3} 이 있다고 가정하자.
    // memo[3] = memo[0] + memo[1] + memo[2] 
    // 3원짜리 동전을 가지고 만드는 경우의 수, 2원짜리 동전을 가지고 만드는 경우의 수 , 1원짜리 동전을 가지고 만드는 경우의 수
    // 왜 memo[1]이 2원짜리 동전을 가지고 만드는 수일까? 2원짜리 동전을 가지고 만들려면 이미 1원이 있어야 하기 때문에!
    // 즉, 현재 X원인 동전을 가지고 있다면, 이 동전을 이용해서 Y원을 만들고 싶다면, DP[Y] = DP[Y] + DP[Y - X]가 된다.
    cout << memo[K];
}
