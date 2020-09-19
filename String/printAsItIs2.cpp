// 그대로 출력하기2 - 11719
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;  
    while (getline(cin, s)) {
        cout << s << "\n";
    }
}
// 참고로 cin >> string;는 공백문자를 스트림에 남겨두는데
// 이 연산뒤에 바로 getline을 하면 getline은 공백문자도 읽기 때문에 공백문자만 읽고 바로 종료된다.
// 따라서 cin.ignore() 해줘야함