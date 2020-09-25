// 텀 프로젝트 - 9466
#include <iostream>
#include <cstring>
#define MAX 100000+4
using namespace std;
// 팀 구성을 위해 함께하고 싶은 학생을 선택해야함
// 혼자 하고 싶은 경우 자기 자신을 선택
// 사이클이 형성되면(팀구성) 사이클에 포함된 노드를 더해서 전체 학생수에서 빼는 문제
// dfs로 사이클 detection
// 👊 다시풀어야함 👊

int n, cnt;
int pick[MAX];
bool visited[MAX];
bool done[MAX];

void dfs(int idx){
    visited[idx] = true;
    int next = pick[idx];
    if(!visited[next]){
        dfs(next);
    }else if(!done[next]){
        for(int i = next; i != idx; i = pick[i]){
            cnt++;
        }// idx가 아닐때까지 for문 돌려서 사이클 개수를 카운트하고
        cnt++;//마지막으로 idx 까지 카운트
    }// 빠져나간곳이 아닌데 visited가 되어있어 ? 사이클!!
    done[idx] = true;// 그다음 빠져나가
}
// 방향 그래프이기 때문에 단순하게 visit만 확인해서는 사이클인지 판단할 수 없다.
// 즉 내가 이미 방문해서 빠져나간곳을 다시 방문하는건 사이클이 아니기 때문에 빠져나갔는지를 기록해야한다(done)

int main(){
    int T;
    cin >> T; // 테스트 케이스 개수
    while(T--){
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> pick[i];
        }

        cnt = 0;
        for(int i = 1; i <=n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        cout << n - cnt <<"\n";
    }
}
