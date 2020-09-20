// 단어의 개수 - 1152
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char ch[1000000];
//방법 1 - for문 돌면서 공백 카운트하고 1더하기 // 맨앞에 공백이 있을 수 있어서 이건 안된다
// int main(){
//     string str;
//     getline(cin, str);
    
//     int cnt = 0;
//     for(int i = 0; i < str.length(); i++){
//         if(str[i] == ' '){
//             cnt++;
//         }
//     }
//     cout << cnt + 1;
// }
// 방법2 - 공백기준으로 잘라서 사이즈 출력 // 메모리 : 2960 KB 시간: 40ms
int main(){
  
    cin.getline(ch, 1000000);
    char *ptr = strtok(ch, " ");
    int cnt = 0;

    while(ptr != NULL){
        cnt++;
        ptr = strtok(NULL, " ");
    }
    cout << cnt; 
}