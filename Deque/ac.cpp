// AC - 5430
// 새로운 언어 AC: 정수 배열에 연산을 하기 위해 만든 언어
// R(뒤집기 => 배열에 있는 숫자의 순서를 뒤집는 함수) D(버리기 => 첫번째 숫자를 버리는 함수)
#include <deque>
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    string p;
    int arrNum;
    string arr; // [1,2,3,4] => 공백없어서 string으로 했음
    deque<int> dq;
    while(T--){
        deque<int>::iterator iter;
        bool print = true;
        bool reverse = false;
        cin >> p; // 명령어 
        cin >> arrNum; // 배열 개수
        cin >> arr; // 배열
        // 0 입력
        // 두 자리수 숫자 입력에서 에러
        string temp;
        for(int i = 0; i < arr.length(); i++){ 
            if(arr[i] == '['){
                continue;
            }
            else if('0' <= arr[i] && arr[i] <= '9'){
                temp += arr[i];
            }
            else if(arr[i] == ',' || arr[i] == ']'){
                if(!temp.empty()){
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
        } // 1 배열 덱에 담음
        for(int i = 0; i < p.length(); i++){
            if(p[i] == 'R'){
                reverse = !reverse;
            }else{
                if(!dq.empty() && reverse){
                    dq.pop_back();
                }
                else if(!dq.empty() && !reverse){
                    dq.pop_front();
                }
                else{
                    cout << "error"<<"\n";
                    print = false;
                    break;
                }
            }
        }
        // 2 명령어 처리
        if(print){
            cout << "[";
            if(reverse){
            while(!dq.empty()){
                cout << dq.back();
                dq.pop_back();
                if(!dq.empty()){
                    cout << ",";
                }
            }
            }
            else{
                while(!dq.empty()){
                cout << dq.front();
                dq.pop_front();
                if(!dq.empty()){
                    cout << ",";
                }
            }
            }
            cout << "]" << "\n";
        }
        // 3 출력
    }
}