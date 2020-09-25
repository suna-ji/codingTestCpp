// 영화감독 숌 - 1436
#include <iostream>
using namespace std;
// 종말의 숫자는 6이 연속으로 3개 이상
// 가장 작은 종말의 숫자는 666이고 이후 1666, 2666...
// N번째로 작은 종말의 숫자를 출력
// 숫자를 666부터 증가시키면서 666이 연속으로 발견되면 cnt를 늘리고 cnt가 n과 같아지는 순간 출력

int main(){
    int n;
    cin >> n;
    string str;
    int number = 666;
    int cnt = 0;
    while(1){
        str = to_string(number);
        if(str.find("666") != -1){
            cnt++;
        }
        if(cnt == n){
            cout << str;
            break;
        }
        number++;
    }
}
