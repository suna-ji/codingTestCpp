// 카드 구매하기 - 11052
#include <iostream>
#include <algorithm>
#define MAX 1000 + 3
using namespace std;

int N;
int memo[MAX];
int numArr[MAX];

// void func(){
//     for(int i = 2; i <= N; i++){
//         if(i % 2 == 0){
//             memo[i] = max((memo[i-1] + numArr[1]), numArr[i]);
//             memo[i] = max(memo[i], memo[i/2] + memo[i/2]);
//         }else{
//             memo[i] = max((memo[i-1] + numArr[1]), numArr[i]);
//         }
//     }
// }
// 처음에 내가 짠거 -> 틀렸음 
void func(){
    memo[1] = numArr[1];
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i; j++){
            memo[i] = max(memo[i], memo[i-j] + numArr[j]);
        }
    }
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numArr[i];
    } 
    func();
    cout << memo[N];
}