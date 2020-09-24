// KMP알고리즘
// 출처: https://m.blog.naver.com/ndb796/221240660061

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;
    
    for(int i = 1; i < patternSize; i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    for(int i = 0; i < table.size(); i++){
        cout << table[i] <<" ";
    }
    cout << "\n";
    return table;
}
void KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for(int i = 0; i < parentSize; i++){
        cout << "i는 "<< i << "   j는  " << j<<"입니다.\n";
        cout << parent[i] <<"와"<< pattern[j]<<"를 비교합니다.\n"; 
        while(j > 0 && parent[i] != pattern[j]){
            cout << "불일치합니다. 이제 j는" << "table["<<j-1<<"] = "<<table[j-1]<<"입니다.\n";
            j = table[j-1]; 
        }
        if(parent[i] == pattern[j]){ // 같다면
            if(j == patternSize - 1){ // 패턴의 끝까지 찾았다면
                cout << i-patternSize+2 <<"에서 찾았습니다.\n";
                cout << "이제 j는" << "table["<<j<<"] = "<<table[j]<<"입니다.\n";
                j = table[j];
            }else{
                j++;
            }
        }
    }
}
int main(){
    string parent = "ABABBABABCABB";
    string pattern = "ABABC";
    KMP(parent, pattern);
    return 0;
}    