// PQ : 우선순위 큐
// * pop연산을 할 때, 우선순위가 가장 높은 원소를 꺼냄
// 출처: https://twpower.github.io/93-how-to-use-priority_queue-in-cpp

#include <iostream>
#include <queue>
using namespace std;

int main(){
    // 1 선언
    priority_queue<int> pq;

    // 2 추가
    pq.push(5);
    pq.push(2);

    // 3 삭제
    pq.pop();

    // 4 top
    cout << pq.top() <<"\n";
    
    // 5 MIN HEAP (최소힙) - pop연산에서 최솟값 꺼냄
    // 5-1 선언으로 최소힙 구현하는 방법
    priority_queue<int, vector<int>, greater<int>> minHeap_pq;
    // 5-2 추가 삭제 연산 수행할 때, -붙여서 구현하는 방법 (1781-컵라면 문제에서 이 방법 사용)
    // pq.push(-homework[i].second); // 일단 넣고
    // printf("%d", -sum);

    // 6 MAX HEAP (최대힙) - pop연산에서 최대값 꺼냄 // 기본형
    priority_queue<int> maxHaep_pq;
}