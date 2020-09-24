// 분해합 - 2231
// 모든 경우를 시도하여 N의 생성자를 구하는 문제
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n; // n의 가장 작은 생성자
    int result;
    int minCreator = 9999999;
    int cnt = 0;                   
    for(int i = 1; i <= n; i++){ // 1부터 n까지 돌면서 분해합이 n이면 min과 비교
        int temp = i;
        result = i;
        while(temp > 0){
            result += temp % 10;
            temp = temp / 10;
        }
        if(result == n){
            cnt++;
            minCreator = min(minCreator, i);
        }
    }
    if(cnt == 0){
        cout << 0 << "\n";
    }// 생성자가 없는 경우 0출력
    else{
        cout << minCreator<<"\n";
    }
    
}