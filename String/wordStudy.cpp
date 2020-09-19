// 단어공부 - 1157
// 단어에서 가장 많이 사용된 알파벳 무엇
// 대소문자 구분 안함
#include <iostream>
using namespace std;

int Alphabet[26];
int main(){
    string word;
    cin >> word;
    for(int i = 0; i < word.length(); i++){
        int ascii = (int)word[i];
        if(ascii > 90){
            ascii -= 97;
        }// 소문자 
        else{
            ascii -= 65;
        }// 대문자
        Alphabet[ascii]++;
    }
    int max = 0;
    int index;
    for(int i = 0; i < 26; i++){
        if(max < Alphabet[i]){
            max = Alphabet[i];
            index = i;
        }
    }
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(max == Alphabet[i]){
            cnt++;
        }
    }
    if(cnt == 1){
        cout << (char)(index+65);
    }else{
        cout << "?";
    }
}