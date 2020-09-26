// 차이를 최대로 - 10819
// 출처: https://yabmoons.tistory.com/98
// 주어진 수열의 경우를 모두 구해서 식을 계산하고 최댓값을 찾는 문제
#include <iostream>
#include <vector>
#include <cmath> // abs 절대값!
#include <algorithm>
using namespace std;
int arr[8];
bool selectArr[8];
vector<int> v;
int n;
int maxResult = -999999;
void calculate(){
    int result = 0;
    for(int i = 0; i < v.size()-1; i++){
        result += abs(v[i]-v[i+1]);
    }
    maxResult = max(maxResult, result);
}
void dfs(int cnt){
    if(cnt == n){ // 어차피 baseCondition으로 와야 return되어 dfs함수가 끝나니까 vector섞이고 이런거 생각안해도 된다. 
        calculate();
        return;
    }// base condition
    for(int i = 0; i < n; i++){
        if(selectArr[i] == true) continue;
        selectArr[i] = true;
        v.push_back(arr[i]);
        dfs(cnt+1);
        v.pop_back();
        selectArr[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; // 3 <= n <= 8
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // result = 0, cnt = 0;
    dfs(0);
    cout << maxResult << "\n";
}