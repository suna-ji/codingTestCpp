// 이친수 - 2193
#include <iostream>
#define MAX 90 + 3
using namespace std;
// 이진수 중 특별한 성질 -> 이친수
// 이친수는 0으로 시작하지 않는다.
// 이친수에서는 1이 두 번 연속으로 나타나지 않는다.
// 즉 11을 부분 문자열로 갖지 않는다.
// ex) 1, 10, 100, 101, 1000, 1001
// N이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.
int N;
long long memo[MAX];
void func(int n){
    for(int i = 3; i <= n; i++){
        memo[i] = memo[i-1] + memo[i-2];
    }
}
int main(){
    cin >> N;
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    func(N);
    cout << memo[N];
}
// 경우의 수 구하기