// 출처: https://yabmoons.tistory.com/100?category=838490
// permutaion 조합 -> 순서가 있음
#include <iostream>
#include <vector>
#define MAX 5
using namespace std;

int arr[MAX];
bool select[MAX];
vector<int> V;

void print(){
    for(int i = 0; i < V.size(); i++){
        cout << V[i] <<" ";
    }
    cout << "\n";
}

// 매개변수 idx없다 왜? idx는 시작점을 결정해주는 매개변수인데, 시작점을 다시 봐줘야하기 때문에 없어진것이다.
void dfs(int cnt){
    if(cnt == 3){
        print();
        return;
    }
    for(int i = 0; i < MAX; i++){
        if(select[i] == true) continue; // 이미 선택했으면 패스
        select[i] = true; // 아니면 선택표시 해주고 
        V.push_back(arr[i]);// 벡터에 넣어줌
        dfs(cnt+1); // dfs돌리고
        V.pop_back(); // 벡터에서 빼줌
        select[i] = false; // select도 false로 바꿔줌
    }
}
// 125를 뽑고 재귀호출이 모두 끝내면 cnt1인 상황이겠지..?
int main(){ 
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5; 
    dfs(0);
}