// KMP는 왜 KMP일까? - 2902
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
// Knuth-Morris-Pratt를 KMP로
int main(){
    char ch[100];
    cin.getline(ch, 100);
    char *ptr = strtok(ch, "-");
    string algorithmName = "";
    while(ptr != NULL){
        algorithmName += ptr[0];
        ptr = strtok(NULL, "-");
    }
    cout << algorithmName;
}

