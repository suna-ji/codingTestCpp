// 카드2 - 2164
// 1~N까지의 번호카드 
// 1번이 제일 위 N이 제일 아래
// 카드가 한 장 남을 때까지 => 제일 위에 있는 카드 버리고 제일 위에 있는 카드 제일 아래에 있는 카드 밑으로 내림
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    queue<int> q;
    for(int i = 1; i <= N; i++){
        q.push(i);
    }
    while(q.size() > 1){ // 카드 한 장 남을때까지 반복
        if(!q.empty()){
            q.pop(); 
        }
        if(!q.empty()){
            q.push(q.front()); // 제일 앞에있는거 뒤로 보내고
            q.pop(); // 맨앞에 있는거 삭제
        }
    }
    cout << q.front();
}