// 블랙잭 - 2798
#include <iostream>
#include <algorithm>
using namespace std;
// 카드의 합이 21일 넘지 않는 한도 내에서, 카드의 합을 최대한 크게 만드는것
// 이 문제는 블랙잭 변형 -> M이 한도 + 카드 3장의 합
int card[100];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> card[i];
    }
    int maxSum = 0;
    for(int i = 0; i <= n-3; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                int sum = card[i] + card[j] + card[k]; // 세장의 카드를 고르는 모든 경우의 수 // for문을 사용한 bruteForce 문제
                if(sum > m) continue;
                maxSum = max(maxSum, sum);
            }
        }
    }  
    cout << maxSum << "\n"; 
}