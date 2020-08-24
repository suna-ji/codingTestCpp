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
            cout << temp << endl;
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