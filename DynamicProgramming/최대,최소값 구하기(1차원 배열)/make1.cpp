// 1로 만들기 - 1463
// 연산 세 개를 적절히 사용해서 1, 연산을 사용하는 횟수의 최솟값
#include <iostream>
#include <cstring>
#define MAX 1000000 + 3
using namespace std;

int memo[MAX]; 
// 재귀 사용한 top-down방식의 문제해결
int func(int n){
    if(n == 1){
        return 0; // 연산횟수 리턴
    }// 1로 만들어야 하니까 이게 base condition
    else{
        int result = 99999999;
        if(n % 2 == 0){
            if(memo[n / 2] == -1){
                memo[n / 2] = func(n / 2);
            }
            result = min(result, memo[n / 2]);
        }
        if(n % 3 == 0){
            if(memo[n / 3] == -1){
                memo[n / 3] = func(n / 3);
            }
            result = min(result, memo[n / 3]);
        }
        if(n-1 >= 1){
            if(memo[n-1] == -1){
                memo[n-1] = func(n-1);
            }
            result = min(result, memo[n-1]);
        }
        return result + 1;
        // func에 들어온 숫자는 1이 아니라면 3가지 경우의 수를 갖는다 -> 2로 나누어 떨어져서 2로 나누거나 3으로 나누어 떨어져서 3으로 나누거나 1을 빼도 1보다 크거나 같아서 1을 빼거나
        // 근데 이 3가지 경우의 수에 대한 결과값 중에서 최소값을 설정해줘야 한다! -> 그래서 else문 앞에 result를 매번 큰 값으로 설정해준다.
    }
}
// 내가 생각하기에 1이 베이스 컨디션이고
// 2로 나눠지면 무조건 2로 나눠서 재귀 돌리고
// 3으로 나눠지면 무조건 3으로 나눠서 재귀 돌리고
// 나머지는 무조건 1을 빼야 2나 3으로 나눠짐
int main(){
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    int ans = func(n);
    cout << ans;
}