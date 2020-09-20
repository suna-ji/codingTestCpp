// 문자열을 O(mlogn)의 시간복잡도로 빠르게 찾는 알고리즘
struct Trie{
    bool finish;
    Trie *next[26];
    Trie(): finish(false){
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for(int i = 0; i < 26; i++){
            if(next[i]){
                delete next[i];
            }
        }
    }
    void insert(const char* key){
        if(*key == '\0'){ // base Condition 들어오는 문자가 null이면 종료
            finish = true;
        }else{
            int curr = *key - 'A'; // 숫자로 변경해줌
            if(next[ ] == NULL){
                next[curr] = new Trie(); // 새로운 TRIE객체 만들고
            } 
            next[curr]->insert(key+1); // 자식에 대하여 다시 insert연산 진행
        }
    }// 재귀적으로 문자열 전체를 순회하면서 끝에 이르면 종료 // 만약 트리가 만들어져있지 않다면 새로운 TRIE객체를 만들어 추가하는 방식

    Trie* find(const char* key){
        if(*key == '\0') return this; // null이면 이 노드를 리턴!
        int curr = *key - 'A';
        if(next[curr] == NULL) return NULL; // 찾는값이 존재하지 않음
        return next[curr] -> find(key+1); // 자식에 대하여 다시 탐색
    }// 문자열이 끝나지 않았는데 true라면 
}