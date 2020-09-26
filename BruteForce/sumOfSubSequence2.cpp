// 부분수열의 합 - 14225
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 부분 수열의 합으로 나올 수 없는 가장 작은 자연수를 구하시오.
int n;
int arr[22];
int selected[22];
int allNum[2000001];
vector<int> vec;
// void dfs(int cnt){
//     if(cnt>=1){
//         int sum = 0;
//         for(int i = 0; i < vec.size(); i++){
//                 sum += vec[i];
//         }
//         allNum[sum] = 1;
//     }
//     for(int i = 0; i < n; i++){
//         if(selected[i] == true) continue;
//         selected[i] = true;
//         vec.push_back(arr[i]);
//         dfs(cnt+1);
//         selected[i] = false;
//         vec.pop_back();
//     }
// }
// 위에 코드는 시간초과 return이 없어서 그런것같음
void dfs(int idx, int sum){
    if(idx == n){
        allNum[sum] = true;
        return;
    }
    dfs(idx+1, sum + arr[idx]); // 선택함
    dfs(idx+1, sum); // 선택안함
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; // 20보다 작음
    for(int i = 0; i < n; i++){
        cin >> arr[i]; // 각 숫자는 100000보다 작음
    }
    sort(arr, arr+ n);
    dfs(0, 0);
    int a = 1;
    while(1){
        if(allNum[a] == 0){
            cout << a << "\n";
            break;
        }
        a++;
    }
}