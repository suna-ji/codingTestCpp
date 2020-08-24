#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string input;
    cin >> input;
    int sum = 0;
    bool isZero = false;

    for(int i = 0; i < input.length(); i++){
        sum += input[i] - '0';
        if(!(input[i]-'0')){
            isZero = true;
        }
    }

    if(isZero && (sum % 3 == 0)){
        sort(input.begin(), input.end(), greater<int>());
        for(int i = 0; i < input.size(); i++){
            cout << input[i];
        }
    }
    else{
        cout << -1;
    }
}