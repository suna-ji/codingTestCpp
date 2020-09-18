// 일파벳 찾기 - 10809
#include <iostream>
using namespace std;
// 각각의 알파벳에 대하여 a가 처음 등장하는 위치, b가 처음 등장하는 위치 출력
int main(){
    string str;
    cin >> str;
    for(int i = 97; i <= 122; i++){
        cout << (int)str.find((char)i) << " ";
    }
}