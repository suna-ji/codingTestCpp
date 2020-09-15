// 별 - 16505
#include <iostream>
using namespace std;

char map[1100][1100];

void func(int N, int i, int j){
    if(N == 1){
        map[i][j] = '*';
        return;
    }

    func(N/2, i, j); 
    func(N/2, i, j+N/2);    
    func(N/2, i+N/2, j);  
} 
int main(){
    int N;
    cin >> N;
    int endPoint = (1 << N);

    for(int i = 0; i < endPoint; i++){
        for(int j = 0; j < endPoint; j++){
            map[i][j] = ' ';
        }
    }
    func(endPoint, 0, 0);
    for(int i = 0; i < endPoint; i++){
        for(int j = 0; j < endPoint - i; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}
