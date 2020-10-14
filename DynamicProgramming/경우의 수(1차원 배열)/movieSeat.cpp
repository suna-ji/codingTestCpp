// 극장 좌석 - 2302
// 고정석을 기준으로 자르고, 경우의 수 구한다음에 곱하면 될듯..?
#include <iostream>
#include <cstring>
#include <vector>
#define MAX 40 + 2
using namespace std;

int N; // 좌석의 개수
int M; // 고정석의 개수
vector<int> ans;
int seatArr[MAX];
int memo[MAX]; // memo[i] : i좌석까지 vip없이 앉는 방법의 경우의 수 
// 점화식
// memo[N] = memo[N-1] + memo[N-2]
// N번 좌석표를 가진 사람이 N번자리에 앉는 경우(본인자리)
// N번 좌석표를 가진 사람이 N-1번 자리에 앉는 경우(왼쪽자리)
void func(int end){
    for(int j = 3; j <= end; j++){
        if(memo[j] == 0){
            memo[j] = memo[j-1] + memo[j-2];
        }
    }
    if(end > 0){
        ans.push_back(memo[end]);
    }
}
int main(){
    cin >> N;
    cin >> M;
    int start = 1;
    int vip;
    int END;
    memo[1] = 1;
    memo[2] = 2;
    for(int i = 0; i < M; i++){
        cin >> vip;
        if(vip == 1){ 
            END = 1;
        }else{
            END = vip - start;    
        }
        func(END);
        start = vip + 1;
    }
    END = (N+1) - start;
    func(END);
    int mul = 1;
    for(int i = 0; i < ans.size(); i++){
        mul *= ans[i];
    }
    cout << mul;
}
