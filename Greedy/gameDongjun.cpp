// 2847- 게임을 만든 동준이
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    int score[101];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &score[i]);
    }
    int sum = 0;
    for(int i = n; i > 1; i--){
        if(score[i-1] >= score[i]){
            sum += score[i-1] - score[i] + 1;
            score[i-1] = score[i] - 1;
        }
    }
    printf("%d", sum);
}