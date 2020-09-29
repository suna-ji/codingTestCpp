// 팰린드롬인지 확인하기 - 10988
#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    int l = str.size();
    int isPalindrome = true;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != str[l-i-1]){
            isPalindrome = false;
        } 
    }
    if(isPalindrome){
        cout << 1 << "\n";
    }else{
        cout << 0 << "\n";
    }
}