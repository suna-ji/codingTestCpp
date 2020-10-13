// LCS  9251
#include <iostream>
#include <algorithm>
#define MAX 1000 + 2
using namespace std;
// longest common subsequence 최장 공통 부분 수열
// 두 수열에서 모두의 부분 수열이 되는 수열 중 가장 긴것
// ACAYKP CAPCAK 의 LCS는 ACAK
// 📌 수열이기 때문에 떨어져있어도 순서만 같으면 된다
// 📌 최장 공통 부분 문자열 (longest common substring)일때는 떨어져있으면 안된다.
string str1, str2;
int memo[MAX][MAX]; // memo[i][j] str1 i까지와 str2 j까지의 최장 공통 부분 수열의 길이

int str1Length;
int str2Length; // 두 문자열의 길이는 다를 수 있다.

void func(){
    for(int i = 1; i <= str1Length; i++){
        for(int j = 1; j <= str2Length; j++){
            if(str1[i-1] == str2[j-1]){
                memo[i][j] = memo[i-1][j-1] + 1;
            }else{
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> str1 >> str2;   
    str1Length = str1.length();
    str2Length = str2.length();
    func();
    cout << memo[str1Length][str2Length];
}