// 잃어버린 괄호 - 1541
#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;
    int result = 0;
    string temp = "";
    bool minus = false;

    for(int i = 0; i <= input.length(); i++){
        if(input[i] == '+' || input[i] == '-' || input[i] == '\0'){
            if(minus){
                result -= stoi(temp);
            }
            else{
                result += stoi(temp);
            }
            temp = ""; 
            if(input[i] == '-')
                minus = true;
            continue;
        }
        temp+= input[i];
    }
    cout << result;
}
// -연산과 + 연산이 번갈아 나오기 때문에 -가 한번 나오면 그 뒤로는 그냥 다 빼주면 된다.
// 