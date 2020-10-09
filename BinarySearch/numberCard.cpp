// 숫자카드 - 10815
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 500000 + 2 
#define numMAX 10000000 + 2
// 숫자카드의 개수가 많다.
// 또한 숫자의 범위도 -10,000,000~10,000,000으로 크다!
// 이분탐색
using namespace std;
int N, M;
int number;
int card[MAX];
//int result[numMAX];
int func(int n){
    int start = 0;
    int end = N-1;
    int mid = 0;
    while(start <= end){
        mid = (start + end) / 2;
        if(card[mid] == n){
            //result[mid] = 1;
            return 1;
        }else{
            if(card[mid] < n){
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
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> card[i];
    }
    sort(card, card + N); 
    cin >> M;
    while(M--){
        cin >> number;
        cout << func(number) << " ";
    }
}