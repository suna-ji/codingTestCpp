// 캠핑 - 4796번
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int L, P, V; // 연속하는 P일 중 L일 사용가능, 이제 막 V일짜리 휴가 시작
    int cnt = 0;
    while(1){
        cnt++;
        scanf("%d %d %d", &L, &P, &V);
        if(!L && !P && !V){
            break;
        }// 종료조건: 0 0 0 
        int result  = 0;
        while(V >= P){
            V -= P;
            result += L;
        }if(L < V){
            result += L;
        }else{
            result += V;
        }
        printf("Case %d: %d\n", cnt, result);
    }
}