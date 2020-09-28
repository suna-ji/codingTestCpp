// 수 찾기 - 1920
#include <iostream>
#include <algorithm>
#define MAX 100000+3
using namespace std;
int n;
int baseArr[MAX];
int binarySearch(int target){
    int start = 0;
    int end = n -1;
    int mid = 0;
    while(start <= end){
        mid = (start + end) / 2;
        if(baseArr[mid] == target){
            return 1;
        }else{
            if(baseArr[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> baseArr[i];
    }
    sort(baseArr, baseArr + n);
    int m;
    int target;
    cin >> m;
    while(m--){
        cin >> target;
        cout << binarySearch(target) << "\n";
    }

}