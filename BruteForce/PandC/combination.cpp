// 출처: https://yabmoons.tistory.com/100
// (차이를 최대로 - 10819) 문제풀다가 처음부터 공부해야겠다는 생각이 들었다.
// Combination 조합 => 순서가 중요하지 않음
// {1,2,3,4,5} 중에 순서 상관없이 3개 뽑기
#include <iostream>
#define MAX 5
using namespace std;

int arr[MAX];
bool select[MAX]; // 만약 중복이 허용되는 조합이라면 select배열은 필요없음

void print(){
    for(int i = 0; i < MAX; i++){
        if(select[i]== true){
            cout << arr[i] <<" ";
        }
    }
    cout << "\n";
}
// idx는 시작점 결정함수 cnt는 몇개 뽑아야 하는지, 원하는 갯수만큼 뽑았는지 판단하는 변수
void dfs(int idx, int cnt){
    if(cnt == 3){
        print();
        return;
    }// base condition 3개 다 뽑았음
    for(int i =  idx; i < MAX; i++){ // (idx ~ 끝)이라는 범위내에서 즉, idx라는 시작점이 정해졌으면 이전에 나온 원소는 쳐다도 안본다.   
        if(select[i] == true) continue; // 이미 뽑혔으면 패스
        select[i] = true; // 뽑았다는 표시 해주고
        dfs(i, cnt + 1); //
        select[i] = false; // N과 M문제처럼 뽑았다는 표시 후 dfs돌리고 다시 false해줘야함~!~!
    }
    // <참고>
    // for문이 아니라 dfs(i+1, cnt+1)로 해도 상관없는데 중복순열 중복조합에서는 계산이 잘못될 가능성이 있다.
}

int main(){
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    dfs(0, 0);
}