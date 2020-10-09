// 다이얼 - 5622
#include <iostream>
using namespace std;

int main(){
    string word;
    cin >> word;
    int length = word.length();
    int result = 0;
    for(int i = 0; i < length; i++){
        int ascii = (int)word[i];
        if(ascii >= 65 && ascii <= 67){
            result += 3;
        } // ABC
        else if(ascii >= 68 && ascii <= 70){
            result += 4;
        } // DEF
        else if(ascii >= 71 && ascii <= 73){
            result += 5;
        }// GHI
        else if(ascii >= 74 && ascii <= 76){
            result += 6;
        }// JKL
        else if(ascii >= 77 && ascii <= 79){
            result += 7;
        }// MNO
        else if(ascii >= 80 && ascii <= 83){
            result += 8;
        }// PQRS
        else if(ascii >= 84 && ascii <= 86){
            result += 9;
        }// TUV
        else{  
            result += 10;
        }// WXYZ
    }
    cout << result;
}