#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char a[51];
    char b[51];
    cin >> a >> b;
    int max = 0;
    
    for(int i = 0; i <= strlen(b) - strlen(a); i++){
        int sum = 0;
        for(int j = 0; j < strlen(a); j++){
            if(a[j] == b[i+j]){
                sum++;
            }
        }
        if(sum > max){
            max = sum;
        }
    }
    cout << strlen(a) - max;
}
