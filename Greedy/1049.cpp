#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int pcost[m], scost[m];
    int min = 99999;
    int sum = 0;
    for(int i = 0; i < m; i++){
        cin >> pcost[i] >> scost[i];
    }
    while(n > 0){
        for(int i = 0; i < m; i++){
            int temp;
            if(n > 6){
                temp = 6;
            }else{
                temp = n;
            }
            if(pcost[i] < (scost[i] * temp)){
                if(min > pcost[i]){
                    min = pcost[i];
                }
            }else{
                if(min >  (scost[i] * temp)){
                    min = scost[i] * temp;
                }
            }
        }
        n -= 6;
        sum += min;
    }
    cout << sum;
}