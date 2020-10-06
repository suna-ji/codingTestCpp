// 제곱수의 합 - 1699
#include<iostream>
#include <cmath>
#define MAX 100000+3
using namespace std;
// 주어진 자연수 N을 제곱수의 합으로 표현할 때 그 항의 최소개수 
int N;
int memo[MAX]; // memo[i] 뜻: i 일때 항의 최소개수 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for(int i = 1; i <= N; i++){
        memo[i] = i;
        for(int j = 1; j * j <= i; j++){
            memo[i] = min(memo[i], memo[i - j * j] + 1);
        }
    }
    cout << memo[N];  
}
// 큰 제곱수부터 빼는 알고리즘의 반례 -> 32 = 4^2 + 4^2
// 동전문제 풀고 다시 푼다.