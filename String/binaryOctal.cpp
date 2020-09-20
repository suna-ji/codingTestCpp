// 2진수 8진수 - 1373
#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 2진수->8진수는 3자리씩 끊어서 10진수로 변환하면 된다.
int main(){
    string str;
    cin >> str;
    int Decimal;
    string result = "";
    stack<int> s;
    for(int i = str.length()-1; i >= 0; i-=3){
        Decimal  = 0;
        if(i >= 0 ){
            Decimal += ((str[i] - '0') * (1 << 0));
        }
        if(i - 1 >= 0){
            Decimal += ((str[i-1] - '0') * (1 << 1));
        }
        if(i - 2 >= 0){
            Decimal += ((str[i-2] - '0') * (1 << 2));
        }
        s.push(Decimal);
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}
