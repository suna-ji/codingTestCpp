#include <iostream>
using namespace std;

int main(){
    int price, change, count;
    count = 0;
    cin >> price;
    change = 1000 - price;
    int coin[6] = { 500, 100, 50, 10, 5, 1};
    for(int i = 0; i < 6; i++){
        if(change >= coin[i]){
            count += change / coin[i];
            change = change % coin[i];
            if(change == 0){
                break;
            }
        }else{
            continue;
        }
        
    }
    cout << count;
}