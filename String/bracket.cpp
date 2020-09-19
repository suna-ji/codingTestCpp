// 괄호 - 9012
// 균형잡힌 세상 - 4949 문제와 유사!
#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
void clear(){
    while(!s.empty()){
        s.pop();
    }
}
int main(){
    int N;
    cin >> N;
    string str;
    bool alreadyFinish;
    for(int i = 0; i < N; i++){
        cin >> str;
        alreadyFinish = false;
        for(int j = 0; j < str.length(); j++){
            if(str[j] == '('){
                s.push(str[j]);
            }else{
                if(!s.empty()){
                    s.pop();
                }else{
                    cout << "NO" << "\n";
                    alreadyFinish = true;
                    break;
                }
            }
        }
        if(!alreadyFinish){
            if(s.empty()){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
        clear();
    }
}