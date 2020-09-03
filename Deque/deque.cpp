// 덱 - 10866
#include <iostream>
#include <deque>
using namespace std;

int main(){
    int N;
    cin >> N;
    string command;
    int operand;
    deque<int> dq;

    while(N--){
        cin >> command;
        if(command == "push_front"){
            cin >> operand;
            dq.push_front(operand);
        }
        else if(command == "push_back"){
            cin >> operand;
            dq.push_back(operand);
        }
        else if(command == "pop_front"){
            if(!dq.empty()){
                cout << dq.front() << '\n';
                dq.pop_front();
            }else{
                cout << -1 <<'\n';
            }
        }
        else if(command == "pop_back"){
            if(!dq.empty()){
                cout << dq.back() << '\n';
                dq.pop_back();
            }else{
                cout << -1 <<'\n';
            }
        }
        else if(command == "size"){
            cout << dq.size() << '\n';
        }
        else if(command == "empty"){
            if(dq.empty()){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }      
        }
        else if(command == "front"){
            if(!dq.empty()){
                cout << dq.front() << '\n';
            }else{
                cout << -1 << '\n';
            }
        }else{ // back
            if(!dq.empty()){
                cout << dq.back() << '\n';
            }else{
                cout << -1 << '\n';
            }
        }
    }
}