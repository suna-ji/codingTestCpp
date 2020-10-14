// 연속합 - 1912
// 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합
// 점화식: memo[0] = numArr[0];
// memo[i] = max((memo[i-1] + numArr[i]), numArr[i]));
// 점화식 처음으로 혼자 만들었다!
#include <iostream>
#include <algorithm>
#define MAX 100000 + 3
using namespace std;
int memo[MAX];
int numArr[MAX];
int N;
void func(){
    for(int i = 2; i <= N; i++){
        memo[i] = max((memo[i-1] + numArr[i]), numArr[i]);
    }
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    }
    memo[1] = numArr[1];
    func();
    int maxSum = -999999;
    for(int i = 1; i <= N; i++){
        maxSum = max(maxSum, memo[i]);
    }
    cout << maxSum;

}

