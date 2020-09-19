// 크로아티아 알파벳 - 2941
#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    int cnt = 0;
    int idx;
    string croatiaArr[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};  
    for(int i = 0; i < 8; i++){
        while(idx !=  -1){
            idx = str.find(croatiaArr[i]);
            if(idx != -1){
                cnt++;
                for(int j = idx; j < idx + croatiaArr[i].length(); j++){
                    str[j] = '.';
                }
            }
        }
        idx = 0;
    }
    for(int i = 0; i < str.length(); i++){
        if(str[i] != '.'){
            cnt++;
        }
    }
    cout << cnt;
}
