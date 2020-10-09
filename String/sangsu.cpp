// 상수 - 2908
// 734 893 -> 상수는 이 숫자를 437 398로 인식
// 이때 상수 기준에서 둘 중 큰 숫자를 출력 (정답은 437)
// 뒤에서 부터 비교하면서 둘중에 큰 숫자가 나오면 그 숫자만 출력..?
// 두 수는 같지 않은 세 자리 수, 0은 포함되어 있지 않다.
#include <iostream>
using namespace std;

int main(){
    string num1;
    string num2;
    int index;
    int big;
    cin >> num1 >> num2;

    for(int i = 2; i >= 0; i--){
        if(num1[i] == num2[i]){
            cout << num1[i];
        }
        else if(num1[i] > num2[i]){
            index = i;
            big = 1;
            break;
        }
        else{
            index = i;
            big = 2;
            break;
        }
    }
    if(big == 1){
        for(int i = index; i >= 0; i--){
            cout << num1[i];
        }
    }else{
        for(int i = index; i >= 0; i--){
            cout << num2[i];
        }
    }
}