// 문자열 폭발 -9935
// #include <iostream>
// using namespace std;
// 문자열의 길이는 1,000,000보다 작거나 같다. O(n)으로 해결해야함
// 문자열 처리가 메인인 스택문제

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     string str, bomb;
//     cin >> str >> bomb;
//     while(1){
//         int idx = str.find(bomb);
//         if(idx == -1){
//             break;
//         }else{
//             string front, back;
//             if(idx == 0){
//                 front = "";
//             }else{
//                 front = str.substr(0, idx);
//             }
//             if(idx+bomb.length() == str.length()){
//                 back = "";
//             }else{
//                 back = str.substr(idx+bomb.length());
//             }
//             str = front + back;
//         }
//     }
//     if(str.length() == 0){
//         cout << "FRULA";
//     }else{
//         cout << str;
//     }
// }
// ---------------------스택으로 수정--------------------------
#include <iostream>
#include <string>
#define MAX 1000003
using namespace std;

string s,bomb;
char result[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> s;
	cin >> bomb;
    int idx = 0;

    for(int i = 0; i < s.length(); i++){
        result[idx++] = s[i];
        if(result[idx-1] == bomb[bomb.length()-1]){ // 넣다가 폭탄의 마지막 문자를 넣었다면 -> 의심
            if((idx - bomb.length()) < 0){
                continue;
            }
            bool detected = true;
            for(int j = 0; j < bomb.length(); j++){ // 폭탄의 길이만큼 뒤로가서 하나씩 비교
                if(result[idx - j - 1] != bomb[bomb.length() - j - 1]){
                    detected = false;
                    break;
                }
            }
            if(detected){ // 찾았다면 
                idx -= bomb.length(); //폭탄의 길이만큼 idx를 감소시켜서 덮어씌움(즉 지움)
            }
        }
    }

    if(!idx){
        cout << "FRULA\n";
    }else{
        for(int i = 0; i < idx; i++){
            cout << result[i];
        }
    }
	
}

