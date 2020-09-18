// 숫자의 개수 - 2577
#include <iostream>
#include <cstring>
using namespace std;

int sumArr[10];

int main(){
    int A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;
    int result = A * B * C;
    string resultStr = to_string(result);
    
    for(int i = 0; i < resultStr.length(); i++){
        sumArr[resultStr[i]-'0']++; // sumArr[resultStr[i]]++; 이렇게 하면 int가 아니라서 안된다
    }
    for(int i = 0; i < 10; i++){
        cout << sumArr[i] << "\n";
    }
}