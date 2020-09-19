// A + B -6 - 10953
#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    string str;
    while(T--){
        cin >> str;
        int a = str[0] - '0';
        int b = str[2] - '0';
        cout << a+b << "\n";
    }
}