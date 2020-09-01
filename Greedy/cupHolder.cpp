// 컴홀더 - 2810
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    string seats;
    cin >> seats;
    int holders = 1;
    int i = 0;
    while(i <= N - 1){
        if(seats[i] == 'S'){
            i+=1;
        }else{
            i+=2;
        }
        holders++;
    }
    if(holders < N){ // 컵홀더보다 사람이 많으면 
        cout << holders;
    }else{
        cout << N;
    }
}