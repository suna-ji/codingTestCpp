// 팩토리얼 - 10872 (피보나치랑 헷갈리지 말자 ㅎ)
// 단순 for문이 아닌 재귀를 활용해서 풀어보자.
#include <iostream>
using namespace std;
int n;
int result;
void factorial(int idx, int result){
    if(idx == 0){
        cout << result;
        return;
    }
    factorial(idx-1, result * idx);
}
int main(){
    cin >> n;
    factorial(n, 1);
}