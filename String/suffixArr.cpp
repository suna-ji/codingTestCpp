// 접미사 배열 - 11656
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 접미사 배열은 문자열 S의 모든 접미사를 사전순으로 배열한 배열이다.
int main(){
    string str;
    cin >> str;
    vector<string> suffixVec;
    for(int i = 0; i < str.length(); i++){
        string suffix = str.substr(i);
        suffixVec.push_back(suffix);
    }
    sort(suffixVec.begin(), suffixVec.end());
    for(int i = 0; i < suffixVec.size(); i++){
        cout << suffixVec[i] << "\n";
    }
}