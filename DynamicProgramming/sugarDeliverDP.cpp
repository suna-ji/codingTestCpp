// 설탕배달 - 2839
// 예전에 그리디로 풀었는데 이번에는 DP로 풀어보자
// 🤮 너무 어럅다 🤮
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> memo;
int main(){
    int N;
    cin >> N;
    memo.clear();
    memo.resize(N+1, -1);
    memo[3] = 1;
    memo[5] = 1;
    
    for(int i = 6; i <= N; i++){
        if(memo[i-3] == -1 && memo[i-5] == -1){
            memo[i] = -1;
            continue;
        }
        if(memo[i-3] == -1){
            memo[i] = memo[i-5] + 1;
            continue;
        }
        if(memo[i-5] == -1){
            memo[i] = memo[i-3] + 1;
            continue;
        }
        memo[i] = min((memo[i-3]+ 1), (memo[i-5] + 1));
    }
    cout << memo[N];
}
