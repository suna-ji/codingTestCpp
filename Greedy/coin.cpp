#include <iostream>
using namespace std;

int main(){
    int n, k, c;
    cin >> n >> k;
    int coin[n];
    int result = 0;
    for(int i = 0; i < n; i++){
        cin >> c;
        coin[i] = c;
    }
    for(int i  = n-1; i >= 0; i--){
        if(coin[i] <= k){
            result += k / coin[i];
            k = k % coin[i];
            n = i+1;
        }
    }
    cout << result;
    return 0;
}