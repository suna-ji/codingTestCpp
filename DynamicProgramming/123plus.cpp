// 1, 2, 3 더하기 - 9095
// 🤮 dp..baseCondition 찾는것도 어려웠음 🤮

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<ll> memo;
int N;
int func(int n){
    if(n == N){
        return 1; // 맞는 경우의 수
    }else{ 
        ll result = 0;
        if(n + 3 <= N){
            if(memo[n+3] == -1){
                memo[n+3] = func(n+3);
            }
            result += memo[n+3];
        }
        if(n + 2 <= N){
            if(memo[n+2] == -1){
                memo[n+2] = func(n+2);
            }
            result += memo[n+2];
        }
        if(n + 1 <= N){
            if(memo[n+1] == -1){
                memo[n+1] = func(n+1);
            }
            result += memo[n+1];
        }
        // 모든 경우의 수를 다 따져야함 -> if else 아님
        return result;
    }
}

/*
int func(int n){
    if(n == N){
        return 1;
    }else if(n > N){
        return 0;
    }else{
        return f(n+1) + f(n+2) + f(n+3);
    }
}
이 코드를 적절하게 메모이제이션 사용해서 위 코드로 변경!
*/ 

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int cnt = 0;
        cin >> N;
        memo.clear();
        memo.resize(N+1, -1);
        cnt = func(0);
        cout << cnt << '\n';
    }
}
