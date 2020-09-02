// N과 M(3) - 15651
#include <iostream>
using namespace std;
//같은 수를 여러번 골라도 된다는 조건이 추가 -> 그럼 백 트랙킹이 필요한건가?.?
int N, M;
int arr[8];

void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        arr[k] = i;
        func(k+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0);
}