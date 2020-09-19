// 그룹 단어 체커 - 1316
// 그룹 단어란 단어에 존재하는 모든 문자에 대해서 각 문자가 연속해서 나타나느 경우만을 말한다.
// 앞에서 나온 알바펫이 뒤에 또 나오면 안된다.
#include <iostream>
#include <cstring>
using namespace std;
int alphabet[26];
int main(){
    int n;
    cin >> n;
    string str;
    int cnt = 0;
    bool finish;
    for(int i = 0; i < n; i++){
        cin >> str;
        finish = true;
        memset(alphabet, 0, sizeof(alphabet));
        alphabet[(int)str[0] - 97] = 1;
        for(int j = 1; j < str.length(); j++){
            if(str[j] != str[j-1]){   
                if(alphabet[(int)str[j] - 97] == 0){
                    alphabet[(int)str[j] - 97] = 1;
                }// 이전에 없었음 -> 이제 있다고 해주자
                else{
                    finish = false;
                    break;
                }
            }// 같지 않으면 이전에 있었는지 확인
        }
        if(finish){
            cnt++;
        }
    }
    cout << cnt;
}
