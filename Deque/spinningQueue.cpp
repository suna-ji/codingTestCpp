// 회전하는 큐 - 1021
#include <iostream>
#include <deque>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    // N: 처음에 포함되어 있던 수 N
    // M: 지민이가 뽑아내려고 하는 원소의 위치
    // 무조건 앞에서만 뽑아낼 수 있음! 이거땜에 헷갈렸다
    
    deque<int> dq;
    int popNum;
    for(int i = 1; i <=N; i++){
        dq.push_back(i);       
    }
    int sum = 0;
    while(M--){
        cin >> popNum;
        deque<int>::iterator iter;

        int cnt = 1;
        for(iter = dq.begin(); iter < dq.end(); iter++){
            if(*iter == popNum){
                break;
            }
            cnt++;
        } // 뽑아내려는 수의 위치

        int left = cnt - 1;
        int right = dq.size() - cnt + 1; // 한번 더 가야해(맨 앞에서만 뽑을 수 있어서)

        if(left < right){ // 2번 연산
            for(int i = 1; i <= left; i++){
                dq.push_back(dq.front());
                dq.pop_front();
                sum++;
            }
        }else{ // 3번 연산  
            for(int i = 1; i <= right; i++){
                dq.push_front(dq.back());
                dq.pop_back();
                sum++;
            }
        }
        dq.pop_front(); // 1번 연산 
    }
    cout << sum << "\n";
}


