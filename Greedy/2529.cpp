#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int K = 0, n;
int a = 9;
int aa = 0;
char C[20];
vector<int> v;
vector<int> v2;

int main(void){
    cin.tie(NULL);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> C[i];
    }
    for(int i = 0; ; i++){
        if(v.size() == n+1) break;
        if(C[i] == "<"){
            K++;
        }
        else{
            
        }
    }
}