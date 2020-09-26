// 포도주 시식- 2156
// 다시 꼭 풀어야함 (계단문제랑 같이 풀자!)
#include <iostream>
#include <algorithm>
using namespace std;
int wine[10001];
int cache[10001];
int n;
int maxSum(){
    cache[1] = wine[1];
    cache[2] = wine[1] + wine[2];
    if(n == 1){ // 1잔일때는 무조건 마시고
        return cache[1];
    }
    else if(n == 2){ // 2잔일때도 무조건 2잔 모두 마시고
        return cache[2];
    }else{ // 3잔부터 dp로 들어간다.
        for(int i = 3; i <= n ; i++){
            //cache[i-1] // i-1까지 (즉 i 이전까지는) 최대로 마셨고 그 뒤로 안마심
            //cache[i-2] + wine[i] // i-2까지 최대로 마셨고 i-1 안마시고(3개 연속 안되니까!!) i마시고
            //cache[i-3] + wine[i-1] + wine[i]  // i-3까지 최대로 마셨고 i-2안마시고 i-1마시고 i마시고
            cache[i] = max(cache[i-1], max(cache[i-2] + wine[i], cache[i-3] + wine[i-1] + wine[i]));
        }
        return cache[n];
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> wine[i];
    }
    cout << maxSum() << "\n";
}