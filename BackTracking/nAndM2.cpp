// N과 M(2) - 15650
#include <iostream>
#include <stdio.h>
using namespace std;
// N과 M(1)문제에서 오름차순이라는 조건이 추가
// arr[i] > arr[i+1] 이면 출력 못함

int N, M;
int arr[9];
bool isUsed[9];

void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!isUsed[i]){
            if(k == 0 || arr[k-1] < i){
                arr[k] = i;
                isUsed[i] = true;
                func(k+1);
                isUsed[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0);
}