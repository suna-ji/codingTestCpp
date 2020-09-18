// OX퀴즈 - 8958
#include <iostream>
using namespace std;
int score[83];
int main(){
    int N;
    cin >> N;
    
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        int sum = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'X'){
                score[i] = 0;
            }else{
                if(i == 0){
                    score[i] = 1;
                }else{
                    score[i] = score[i-1] + 1;
                }
                sum += score[i];
            }
        }
        cout << sum << "\n";
    }
}