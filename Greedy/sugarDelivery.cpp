// 설탕 배달 - 2839
// 3키로 5키로 봉지있음
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int fiveMax = N / 5;
    int threeMax = N / 3;
    int ans = -1;
    for(int i = 0; i <= fiveMax; i++){
        for(int j = 0; j <= threeMax; j++){
            if(N == 5 * i + 3 * j){
                ans = i+j;
                break;
            }
        }
    }
    cout << ans;
}