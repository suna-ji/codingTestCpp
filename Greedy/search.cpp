#include <iostream>
#include <string>
using namespace std;

int main(){
    string document;
    string word;
    getline(cin, document);
    getline(cin, word);
    int index = document.find(word);
    int sum = 0;
    int wordLength = word.length();
    while(index > -1){
        sum++;
        index = document.find(word, index + wordLength);
    }
    cout << sum << endl;
}