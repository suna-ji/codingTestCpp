// 크게 만들기 - 2812
#include <iostream>
#include <string>
#include <deque> // 큐가 응용된 형태(덱) double-ended queue
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin >> N >> K;

    string s;
    cin >> s;

    deque<char> dq;
    for(unsigned int i = 0; i < s.length(); i++){
        while(K && !dq.empty() && dq.back() < s[i]){ // 아직 뻴 기회 남았고 dq가 비지 않았고 dq의 마지막이 들어올애보다 작으면 뺀다.
            dq.pop_back();
            K--;
        }
        dq.push_back(s[i]);
    }

    for(unsigned int i = 0; i < dq.size() - K; i++){ // 큰 순서대로 입력을 받았다면 큐에 다 들어감 -> 뒤에서 K개는 출력 안하도록
        cout << dq[i];
    }
}
