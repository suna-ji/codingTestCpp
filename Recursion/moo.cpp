// Moo 게임 - 5904
// S(k) = S(k-1) + Mo...o(k+2개) + S(k-1)

#include<iostream>
using namespace std;
string str;
string temp;
string func(int n, string temp, string str){
    if(n == 0){
        str = str + "moo" + str;
        return str;
    }
    for(int i = 0; i < n+2; i++){
        temp = temp + "o";
    }

    func(n-1, temp, str);
}
int main(){
    int n;
    cin >> n;
    func(n, "", "");
    cout << str[n];
}
// 포기