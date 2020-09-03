// 에디터 - 1406
#include <iostream>
#include <string>
#include <list>
#include <functional> 
using namespace std;
list<char> l;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s; 
    for(int i = 0; i < s.length(); i++){
        l.push_back(s[i]);
    }
    // 1 문자열 받고 리스트에 넣기

    int M;
    cin >> M;
    char command, operand;
    list<char>::iterator cursor = l.end();
    //auto cursor = l.end(); // end iterator 
    for(int i = 0; i < M; i++){
        cin >> command;
        if(command == 'L'){ // 커서 왼쪽으로 (문장의 맨 앞이면 무시)
            if(cursor != l.begin()){
                cursor--;
            }
        }
        else if(command == 'D'){ // 커서 오른쪽으로 (문장의 맨 뒤이면 무시)
            if(cursor != l.end()){
                cursor++;
            }
        }else if(command == 'B'){ // 커서 왼쪽에 있는 문자 삭제
            if(cursor != l.begin()){
                cursor--;
                cursor = l.erase(cursor); // erase는 제거한 다음 원소의 위치를 반환
            }
        }else{ // P $ 주어진 문자를 커서 왼쪽에 추가
            cin >> operand;
            l.insert(cursor, operand);
        }
    }
    // 2 명령어 받아서 처리

    for(cursor = l.begin(); cursor != l.end(); cursor++){ 
        cout << *cursor; 
    }    
    // 3 명령어 처리 끝난 결과 출력

}