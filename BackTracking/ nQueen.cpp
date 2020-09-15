// N-Queen - 9663
#include <iostream>
using namespace std;
bool isUsed1[40]; // 열이 겹치는지 체크 
bool isUsed2[40]; // / 방향 대각선을 차지하고 있는지
bool isUsed3[40]; // \ 방향 대각선을 차지하고 있는지

int cnt = 0;
int n;
// N-Queen 문제는 크기가 N * N 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
// N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
void func(int cur){ // cur번째 row에 말을 배치할 예정임
    if(cur == n){ // 퀸 N개를 놓는데 성공
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){ // (cur, i)에 퀸을 놓을 예정
        if(isUsed1[i] || isUsed2[i+cur] || isUsed3[cur - i + n -1]){
            continue;
        } // column이나 대각선 중에 문제가 있다면
        isUsed1[i] = true; 
        isUsed2[i + cur] = true;
        isUsed3[cur - i + n -1] = true;
        func(cur+1);
        isUsed1[i] = false;
        isUsed2[i + cur] = false;
        isUsed3[cur - i + n -1] = false;
    }
}

int main(){
    cin >> n;
    func(0);
    cout << cnt;
}