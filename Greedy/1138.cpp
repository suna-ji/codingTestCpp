#include <iostream>
using namespace std;


int main(){
    int n, left;
    cin >> n;
    int p[10]; 

    for(int i = 0; i < n; i++){
        cin >> left;
        for(int j = 0; j < n; j++){
            cout << "i--->" << i << "j--->" << j <<  endl;
            if(left == 0 && p[j] == 0){
                p[j] = i+1;
                break;
            }else if(p[j]==0){
                left--;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << p[i] << ' ';
    }
}