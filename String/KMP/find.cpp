// 찾기 - 1786
// kmp 알고리즘 O(N+M)
#include <iostream>
#include <vector>
using namespace std;
vector<int> result;
vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0); // pattern사이즈만큼 0으로 초기화
    int j = 0;
    for(int i = 1; i < patternSize; i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j; 
        }
    }
    return table;
}

void kmp(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0; 
    for(int i = 0; i < parentSize; i++){
        while(j > 0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternSize-1){
                result.push_back(i-patternSize+2);
                j = table[j];
            }else{
                j++;
            }
        }
    }
}
int main(){
    string T;
    string P;
    // 문자열 내에 공백이 포함되어 있을 수도 있음에 유의한다.
    getline(cin, T);
    getline(cin, P);
    kmp(T, P);
    cout << result.size()<< "\n";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << "\n";
    }
}