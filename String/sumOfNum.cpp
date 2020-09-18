// 숫자의 합 - 11720
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    string numStr;
    cin >> numStr;
    int sum = 0;
    for(int i = 0; i < numStr.length(); i++){
        sum += numStr[i]-'0';
    }
    cout << sum;
}