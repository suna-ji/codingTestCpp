// 히앤 킨 - 1100
#include <iostream>
using namespace std;
char map[8][8];

int main(){
    int cnt = 0;
    char ch;
   
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = i % 2; j < 8; j+=2){
            if(map[i][j] == 'F'){
                cnt++;
            }
        }
    }
    cout << cnt;
}
