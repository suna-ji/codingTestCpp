// 암호코드 - 2011
#include <iostream>
#define Moduler 1000000
#define MAX 5000 + 3
using namespace std;
// A->1 B->2 ... Z->26
// 어떤 암호가 주어졌을 때, 그 암호의 해석이 몇가지
int memo[MAX]; // memo[i]: 길이가 i일때 암호 해석의 경우의 수
int Arr[MAX];
int main(){
    string code;
    cin >> code;
    int len = code.length();
    for(int i = 1; i <= len; i++){
        Arr[i] = code[i-1] - '0';
    }
    memo[0] = 1;
    for(int i = 1; i <= len; i++){
        if(Arr[i] >= 1 && Arr[i] <= 9){ // 1~9
            memo[i] = (memo[i-1] + memo[i]) % Moduler;
        }
        if(i == 1) continue; // 첫번째 단어 -> 2개를 하나의 단어로 취급할 수 없음
        int temp = Arr[i] + Arr[i-1] * 10;
        if(temp >= 10 && temp <= 26){ // 
            memo[i] = (memo[i-2] + memo[i]) % Moduler;
        }
    }
    cout << memo[len] << "\n";
}