// 연산자 끼워넣기 - 14888
// 모든 경우의 수 고려 -> DFS통해서 해결
#include <iostream>
using namespace std;
int n;
int arr[11];
int operatorArr[4]; // 덧셈 뺄셈 곱셈 나눗셈 
int minResult = 1000000001;
int maxResult = -1000000001;

void dfs(int plus, int minus, int multiply, int divide, int idx, int sum){
    if(idx == n){
        maxResult = max(maxResult, sum);
        minResult = min(minResult, sum);
    }
    if(plus > 0)
        dfs(plus-1, minus, multiply, divide, idx+1, sum + arr[idx]);
    if(minus > 0)
        dfs(plus, minus-1, multiply, divide, idx+1, sum - arr[idx]);
    if(multiply > 0)
        dfs(plus, minus, multiply-1, divide, idx+1, sum * arr[idx]);
    if(divide > 0)
        dfs(plus, minus, multiply, divide-1, idx+1, sum / arr[idx]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> operatorArr[i];
    }
    dfs(operatorArr[0], operatorArr[1], operatorArr[2], operatorArr[3], 1, arr[0]);
    cout << maxResult << "\n";
    cout << minResult << "\n";
}