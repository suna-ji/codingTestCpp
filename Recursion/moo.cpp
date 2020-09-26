// Moo 게임 - 5904
// S(k) = S(k-1) + Mo...o(k+2개) + S(k-1)

#include<iostream>
using namespace std;
string str;
string temp;

// void func(int n, string temp, string str){
//     if(n == 0){
//         cout << str[n];
//         return;
//     }
//     temp = temp + "o";
//     func(n-1, temp, str + temp + str);
// }
// int main(){
//     int n;
//     cin >> n;
//     func(n, "moo" ,"moo");
// }
// 출력은 이제 해결, 시간초과도 해결, 근데 메모리 초과함..ㅠ
// 또한, n<=1e9라면  재귀호출도 10억번이나 발생하는데 최대 재귀 호출 수 초과로 런타임 에러와 재귀호출에 필요한 메모리 사용으로 메모리 초과를 일으킵니다.
// 답변 출처 : https://www.acmicpc.net/board/view/54792
// 점화식으로 해당 문자를 찾아야할듯
// 다음에..