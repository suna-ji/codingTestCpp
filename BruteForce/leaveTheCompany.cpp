// 퇴사 - 14501
#include <iostream>
#include <utility>
using namespace std;
// 각각의 상담은 상담을 완료하는데 걸리는 기간(T)과 금액(P)으로 구성
// 상담을 적절히 했을 때, 최대 수익 구해라
// 최대 일수가 15일 -> 모든 경우의 수 구해서 푸는 bruteForce
int n; // 최대 15
int t[15];
int p[15];
int maxMoney = -9999999;

void func(int money, int time){
    if(time > n){ // base condition n일을 넘어가면 종료
        return;
    }
    if(money > maxMoney){
        maxMoney = money;
    }
    for(int i = time; i < n; i++){
        if(i + t[i] < n+1){ // 현재까지의 일수에서 할수있는 시간만큼 더해줬을 때 n보다 작다면 재귀 함수 호출 (n일까지는 회사에서 상담가능)
            func(money + p[i], i + t[i]);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t[i] >> p[i];
    }
    func(0,0); // 돈 0 오늘 0번째날 
    cout << maxMoney;
}