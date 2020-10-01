// 파도반 수열 - 9461
#include <iostream>
#define MAX 100+3
using namespace std;
long long memo[100];
void func(int n){
    for(int i = 9; i <= n; i++){
        if(memo[i] == 0){
            memo[i] = memo[i-5] + memo[i-1];
        }
    }
}
int main(){
    int T, N;
    cin >> T;
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 1;
    memo[4] = 2;
    memo[5] = 2;
    memo[6] = 3;
    memo[7] = 4;
    memo[8] = 5;
    while(T--){
        cin >> N;
        func(N);  
        cout << memo[N] << "\n";  
    }
}