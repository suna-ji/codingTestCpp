// 제로 - 10773
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int k, n;
    cin >> k;
    stack<int> s;
    while(k--){
        cin >> n;
        if(n == 0){
            s.pop();
        }else{
            s.push(n);
        }
    }
    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum;
}