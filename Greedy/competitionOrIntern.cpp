#include <iostream>
using namespace std;

int main(){
    int n,m,k;
    int sum = 0;
    cin >> n >> m >> k;
    while(1){
        if((n-2+m-1) >=k && n >= 2 && m >=1){
            n -= 2;
            m -= 1;
            sum++;
        }else{
            break;
        }
    }
    cout << sum;
}
