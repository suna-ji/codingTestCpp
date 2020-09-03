//큐 - 10845
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    string command;
    int operand;
    queue<int> q;
    while(N--){
        cin >> command;
        if(command == "push"){
            cin >> operand;
            q.push(operand);
        }
        else if(command == "pop"){
            if(!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }else{
                cout << -1 << "\n";
            }
        }
        else if(command == "size"){
            cout << q.size() << '\n';
        }
        else if(command == "empty"){
            if(q.empty()){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }
        else if(command == "front"){
            if(!q.empty()){
                cout << q.front() << '\n';
            }else{
                cout << -1 << "\n";
            }
        }else{ // back
            if(!q.empty()){
                cout << q.back() << '\n';
            }else{
                cout << -1 << "\n";
            }
        }
    }   
}