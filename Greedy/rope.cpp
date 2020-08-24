#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int rope[n];
   
    for(int i = 0; i < n; i++){
        cin >> rope[i];
    }
    sort(rope, rope+n);
    int max = rope[0] * n;
    for(int i = 0; i < n; i++){
        if(max <= (rope[i+1]*(n-i-1))){
            max = rope[i+1] * (n-i-1);
        }
    }
    cout << max;
}