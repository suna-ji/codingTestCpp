// 팰린드롬? - 10942
// 거꾸로 읽어도 같은거
#include <iostream>
#include <string>
using namespace std;
int numbers[2003];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a;
    for(int i = 1; i <= n; i++){
        cin >> a;
        numbers[i] = a;
    }
    int QNum;
    cin >> QNum;
    int s, e;

    while(QNum--){
        cin >> s;
        cin >> e;
       
        int f;
        int stop = false;
        if(s-e+1 % 2 == 0){
            f = e / 2 + 1;
        }// 짝수면
        else{
            f = e / 2;
        }// 홀수이면
        for(int i = s; i <= f; i++){
            if(numbers[i] != numbers[e-i+1]){
                cout << 0 <<"\n";
                stop = true;
                break;
            }
        }
        if(!stop){
            cout << "1" << "\n";
        }   
    }
    
}
// DP하는날 다시한다.