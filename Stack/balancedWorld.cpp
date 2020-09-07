// 균형잡힌 세상 - 4949
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> stack; 
   
    while(1){
        string s;
        getline(cin, s); 
        bool finish = true;
        while( !stack.empty() ) stack.pop();
        if(s[0] == '.'){
            break;
        }
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '['){
                stack.push(s[i]);
            }
            else if(s[i] == ')'){
                if(!stack.empty()){
                    if(stack.top() == '('){
                        stack.pop();
                    }else{
                        cout << "no" <<"\n";
                        finish = false;
                        break;
                    }
                }else{
                    cout << "no" << "\n";
                    finish = false;
                    break;
                }
            }
            else if(s[i] == ']'){
                if(!stack.empty()){
                    if(stack.top() == '['){
                        stack.pop();
                    }else{
                        cout << "no" <<"\n";
                        finish = false;
                        break;
                    }
                }else{
                    cout << "no" << "\n";
                    finish = false;
                    break;
                }
            }
        }
        if(finish && stack.empty()){
            cout << "yes" << "\n";
        }
        if(finish && !stack.empty()){
            cout << "no" << "\n";
        }
    }
}