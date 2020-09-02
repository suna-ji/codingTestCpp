// N 과 M(4) - 15652
// 같은 수 여러번 고를 수 있고 수열은 비내림차순 
#include <stdio.h>
#include <iostream>
using namespace std;

int N, M;
int arr[8];
void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        } 
        cout << '\n';
        return;  
    }
    for(int i = 1; i <= N; i++){
        if(k == 0 || arr[k-1] <= i){
            arr[k] = i;
            func(k+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0);
}