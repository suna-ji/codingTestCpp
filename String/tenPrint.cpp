// 열 개씩 끊어 출력하기 - 11721
#include <iostream>
#include <string>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    string s;
    cin >> s;

    int cnt = s.length() / 10; 
    if (s.length() % 10)
        cnt++; // 나머지 있다면 반복횟수 1 늘려줌
    for (int i = 0; i < cnt - 1; i++)
        cout << s.substr(i * 10, 10) << "\n";
    cout << s.substr((cnt - 1) * 10) << "\n"; // 문자열 끝까지
}
