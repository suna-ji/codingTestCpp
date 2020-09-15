// 우유축제 - 14720
#include <iostream>
#include <stack>
using namespace std;
// 딸기->초코->바나나->딸기
// 영향이가 마실 수 있는 우유의 최대 개수
int main(){
    int N;
    cin >> N;
    stack<int> s;
    int arr[1003];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++){
        if(s.empty() && arr[i] == 0){ // 맨 처음에는 딸기우유를 먹는다.
            s.push(arr[i]);
        }
        if(!s.empty()){
            if(s.top() == 0 && arr[i] == 1){ // 딸기 -> 초코
                s.push(arr[i]);
            }
            else if(s.top() == 1 && arr[i] == 2){ // 초코 -> 바나나
                s.push(arr[i]);
            }
            else if(s.top() == 2 && arr[i] == 0){ // 바나나 -> 딸기
                s.push(arr[i]);
            }
        }
    }
    cout << s.size();

}