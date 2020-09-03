// 스택 - 10828
// 정수를 저장하는 스택을 구현하고 명령 처리
#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    int N;
    cin >> N;
    string command;
    int operand;
    while(N--){
        cin >> command;
        if(command == "push"){
            cin >> operand;
            s.push(operand);
        }
        else if(command == "pop"){
            if(!s.empty()){
                cout << s.top() << '\n';
                s.pop();
            }else{
                cout << -1 << '\n';
            }
        }
        else if(command == "size"){
            cout << s.size() << '\n';
        }
        else if(command == "empty"){
            if(s.empty()){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }else{ // top
            if(!s.empty()){
                cout << s.top() << '\n';
            }else{
                cout << -1 <<'\n';
            }
        }
    }
}