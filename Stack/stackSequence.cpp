// 스택 수열 - 1874
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n; 
    int num;
    stack<int> s;
    queue<int> q;
    string result = "";
    for(int i = 0; i < n; i++){
        cin >> num;
        q.push(num);
    }
    int idx = 1;
    int isStop = false;
    while(1){
        if(q.empty()){
            break;
        }
        if(s.empty() && idx <= n){
            s.push(idx);
            result += '+';
            idx++;
        }else{
            if(s.top() == q.front()){
                s.pop();
                q.pop();
                result += '-';
            }else if(s.top() < q.front() && idx <= n){
                s.push(idx);
                idx++;
                result += '+';
            }else if(s.top() > q.front()){
                cout << "NO";
                isStop = true;
                break;
            }
        }
    }
    if(!isStop){
        for(int i = 0; i < result.length(); i++){
            cout << result[i] << "\n";
        }
    }
}