// 한수 - 1065
// 양의 정수 X의 각 자리가 등차수열
// n보다 작거나 같은 한수의 개수 출력
#include <iostream>
#include<stdlib.h>// 절대값 함수 abs()
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    string str;
    for(int i = 1; i <= n; i++){ // 양의 정수
        str = to_string(i);
        int isHansu = true;
        if(str.length() < 3){
            cnt++;
        }else{
            int cd = (str[1]-'0') - (str[0]-'0');
            for(int j = 1;  j < str.length() -1; j++){
                int temp = (str[j]-'0') + cd;
                if(temp != (str[j+1]-'0')){
                    isHansu = false;
                    break;
                }
            }
            if(isHansu){
                cnt++;
            }
        }
    }
    cout << cnt;
}