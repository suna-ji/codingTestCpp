// 차이를 최대로 - 10819
#include <iostream>
#include <algorithm>
using namespace std;
int arr[8];
int maxResult = -999999;
void func(int idx, int result, int cnt){
    if(cnt == n/2){
        maxResult = max(maxResult, result);
        return;
    }// base condition
    func(idx+2,,cnt++)
}

int main(){
    int n;
    cin >> n; // 3 <= n <= 8
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    func(0, 0, 0);
}