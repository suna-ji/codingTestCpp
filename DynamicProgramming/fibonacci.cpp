// 피보나치 함수 - 1003번
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int f[41];

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(f[n]) return f[n];
    return f[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int T, N; // T: 테스트케이스 개수, N: 40보다 작거나 같은 자연수 또는 0
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        cin >> N;
        memset(f, 0, sizeof(f));
        if(N == 0){
            cout << 1 << " " << 0 << endl;

        }else{
            cout << fibonacci(N-1) << " "<< fibonacci(N) << endl; // 공백으로 구분해서 0의 호출횟수, 1의 호출횟수 출력
        }
    }
}