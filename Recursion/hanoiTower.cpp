// 하노이 탑 - 11729
#include <iostream>
using namespace std;

void func(int a, int b, int n){
    if(n == 1){
        cout << a << " " << b << "\n";
        return;
    }// base condition 
    func(a, 6-a-b, n-1); // n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
    cout << a << ' ' << b << "\n"; // n번 원판을 a에서 b로 옮긴다.
    func(6-a-b, b, n-1); // n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.
}
// 1 n-1개의 원판을 기둥 1에서 기둥2로 옮긴다.
// 2 n번 원판을 기둥 1에서 3으로 옮긴다.
// 3 n-1개의 원판을 기둥 2에서 기둥 3으로 옮긴다.


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    cout << (1 << k) -1 << "\n";
    func(1, 3, k);
}