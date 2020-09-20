// 농구경기 - 1159
#include <iostream>
using namespace std;
// 상근이는 농구의 세계에서 점차 영향력을 넓혀가고 있다.
int alphabet[26];

int main(){
    int n;
    cin >> n;
    string name;
    while(n--){
        cin >> name;
        int idx = (int)name[0] - 97;
        alphabet[idx]++;
    }
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(alphabet[i] >= 5 ){
            cout << (char)(i+97);
            cnt++;
        }
    }
    if(cnt == 0){
        cout << "PREDAJA";
    }
}