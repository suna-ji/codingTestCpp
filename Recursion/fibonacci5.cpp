// 피보나치 수 5 - 10870
// 재귀를 활용하여 풀어보자
#include <iostream>
using namespace std;
int n;
int result = 0;
int fibonacci(int idx){
    if(idx == 0){
        return 0;
    }
    if(idx == 1){
        return 1;
    }
    return fibonacci(idx-1) + fibonacci(idx-2);
}
int main(){
    cin >> n;
    cout << fibonacci(n);
}