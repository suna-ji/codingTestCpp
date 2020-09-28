// 피보나치 수 2 - 2748
#include <iostream>
using namespace std;
// 피보나치 수는 0과 1로 시작한다
// 0번째 피보나치 수는 0이고 1번째 피보나치 수는 1이다.
// 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다. -> 여기서부터 DP
// Fn = Fn-1 + Fn-2(n>=2)
// n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
int n;
long long f[92];
long long fibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }
    if(f[n]) return f[n];
    return f[n] = fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    cin >> n;
    cout << fibonacci(n);
}