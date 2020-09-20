// 전화번호 목록 - 5052
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// 1. 전화번호 트라이에 입력
// 2. 트라이에 등록 후, 전화번호를 찾음 
// 3. 이때 전화번호가 끝나지 않았는데 마지막 문자라고 표시되면 NO를 출력
// 예)  911234와 911이라는 번호가 있다.
// 911에서 마지막 1이 finish로 등록되어있다.
// 이 상황에서 911234를 찾아가는데 아직 저 전화번호가 끝나지 않았는데 finish를 발견 -> 일관성 없음 -> NO출력
char pNumbers[10000][11];
struct TRIE{
    bool finish;
    TRIE* Next[10]; // 0 ~ 9
    // 생성지
    TRIE(){
        finish = false;
        memset(Next, 0, sizeof(Next));
    }
    // 소멸자
    ~TRIE(){
        for(int i = 0; i < 10; i++){
            if(Next[i]){
                delete Next[i];
            }
        }
    }
    void insert(const char* key){
        if(*key == '\0'){
            finish = true;
        }//base Condition
        else{
            int curr = *key- '0';
            if(Next[curr] == NULL){
                Next[curr] = new TRIE();
            }
            Next[curr]->insert(key+1);
        }
    }

    bool find(const char* key){
        if(*key == '\0'){
            return 0;
        }
        if(finish){
            return 1;
        }
        int curr = *key - '0';
        return Next[curr]->find(key+1);
    }
};
int main(){
    int t;
    cin >> t;
    int n;
    int r;

    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> pNumbers[i];
        }
        TRIE *root = new TRIE;
        r = 0;
        for(int i = 0; i < n; i++){
            root->insert(pNumbers[i]);
        }
        for(int i = 0; i < n; i++){
            if(root->find(pNumbers[i])){
                r = 1;
            }
        }
        if(r == 1){
            cout << "NO" << "\n";
        }else{
            cout << "YES" << "\n";
        }
    }
}