#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> p;
p homework[200000];
priority_queue<int> pq;
int n;

int main(){
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &homework[i].first, &homework[i].second);
    }
    sort(homework, homework + n);
    // 입력 및 전처리 끝
    int dl;
    for(int i = 0; i < n; i++){
        pq.push(-homework[i].second); // 일단 넣고
        dl = homework[i].first;
        while(dl < pq.size()) // 마감일에 처리할 수 없다면 맨위에 있는거 pop(가장 작은 수)
            pq.pop();
    }
    int sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }// 남은것들만 더해서 -붙여서 출력
    printf("%d", -sum);
    return 0;
}
// 1781번
// 참고한 블로그: https://js1jj2sk3.tistory.com/12 