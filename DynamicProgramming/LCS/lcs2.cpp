// LCS2 - 9252
// LCS1과의 차이점 -> LCS길이 뿐만 아니라 LCS도 출력해야함
// LCS? Longest Common Subsequence 최장 공통 부분 수열
// 📌 수열이기 때문에 떨어져 있어도 상관없음 순서만 같으면 된다.
// 너무 어렵네..https://www.youtube.com/watch?v=sSno9rV8Rhg 참고..
// 굿노트에 정리해놨음
#include <iostream>
#define MAX 1000 + 2
using namespace std;
string str1, str2;
int memo[MAX][MAX]; // str1 i까지, str2 j까지 최장 공통 수열
int main(){
    cin >> str1;
    cin >> str2;
    int length1 = str1.length();
    int length2 = str2.length();
    string lcs= "";
    for(int i = 1; i <= length1; i++){
        for(int j = 1; j <= length2; j++){
            if(str1[i-1] == str2[j-1]){
                memo[i][j] = memo[i-1][j-1] + 1;
                
            }else{
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }
    // 2차원 배열을 역추적하여 LCS 저장
    int i = length1;
    int j = length2;
    while(i!=0 && j!=0){
        if(memo[i][j] == memo[i-1][j]){ // ij가 위(상)와 같다면
            i--;
        }else if(memo[i][j] == memo[i][j-1]){ // ij가 왼쪽(좌)과 같다면
            j--;
        }else{ // 둘다 같지 않다면 -> 즉 상, 좌보다 1증가 (같아서 증가)
            lcs += str1[i-1]; // 추가
            i--;
            j--;
        }
    }
    cout << memo[length1][length2] << "\n";
    int lcsLen = lcs.length();
    for(int i = lcsLen-1; i >= 0; i--){ // 역추적 -> 역으로 출력
        cout << lcs[i];
    }
}