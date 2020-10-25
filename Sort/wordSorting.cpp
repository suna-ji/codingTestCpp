// 1181 - 단어정렬
// 소문자로 이루어진 N개의 단어가 들어오면, 정렬하라
// 1. 길이가 짧은 것부터
// 2. 길이가 같으면 사전 순으로
// * 같은 단어가 여러번 들어오면 한번만 출력하라
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> wordVec;
bool compare(string a, string b){
    if(a.size() == b.size()){ // 조건2 길이가 같으면 사전순으로
        return a < b;
    }else{ // 조건1 길이가 짧은 것부터
        return a.size() < b.size();
    }// 
}
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 빠른 입출력
    cin >> N;
    string word;
    while(N--){
        cin >> word;
        wordVec.push_back(word);
    }
    sort(wordVec.begin(), wordVec.end(), compare);
    wordVec.erase(unique(wordVec.begin(),wordVec.end()),wordVec.end());
    for(int i = 0; i < wordVec.size(); i++){
        cout << wordVec[i] << "\n";
    }
}