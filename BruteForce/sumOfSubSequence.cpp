// 부분수열의 합 - 1182
// 정수의 개수 N 정수 S (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 
// 주어지는 정수의 절댓값은 100,000을 넘지 않는다.
// 🤯 다시풀기 🤯
#include <iostream>
using namespace std;
int n, s;
int ans = 0;
int arr[20];

void func(int index, int sum){
    sum += arr[index];
    if(index >= n){
        return;
    }
    if(sum == s){
        ans++;
    } 
    func(index+1,sum-arr[index]);
    func(index+1,sum);
}   

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    func(0, 0);
    cout << ans;
}