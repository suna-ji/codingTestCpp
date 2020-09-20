// 문자열 집합 - 14425
#include <iostream>
#include <cstring>
using namespace std;
// 총 n개의 문자열로 이루어진 집합 s가 주어진다.
// 입력으로 주어지는 m개의 문자열 중에서 집합 s에 포함되어 있는 것이 총 몇개인지 구하는 프로그램을 작성하시오.
struct Trie{
    bool finish;
    Trie* next[26]; // 알파벳 소문자로만 이루어져있다.
    //생성자
    Trie(){
        finish = false;
        memset(next, 0, sizeof(next));
    }
    //소멸자
    ~Trie(){
        for(int i = 0; i < 26; i++){
            if(next[i]){
                delete next[i];
            }
        }
    }
    void insert(const char* key){
        if(*key == '\0'){
            finish = true;
        }else{
            int curr = *key - 'a';
            if(next[curr] == NULL){
                next[curr] = new Trie;
            }
            next[curr]->insert(key+1);
        }
    }
    bool find(const char* key){
        if(*key == '\0'){ // 끝까지 해서 찾았다 
            if(finish){ // 그리고 찾은 문자열도 끝이다(apple에서 apple찾은 경우)
                return 1;
            }else{
                return 0;
            }// apple 중 app찾은경우
        }
        if(finish){ // 중간에 finish를 만났다 -> 1 리턴
            return 0;
        }
        int curr  = *key - 'a';
        if(next[curr] == NULL) return 0;
        return next[curr]->find(key+1); // 타입!!
    }

};
int main(){
    int n, m;
    cin >> n >> m;
    char baseWord[500];
    char findWord[500];
    Trie* root = new Trie;
    int cnt = 0;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cin >> baseWord;
        root->insert(baseWord);
    }// 집합 s에 포함되어 있는 문자열

    for(int i = 0; i < m; i++){
        cin >> findWord;
        if(root->find(findWord)){
            cnt++;
        }
    }// 검사해야 하는 문자열
    cout << cnt;
}

 