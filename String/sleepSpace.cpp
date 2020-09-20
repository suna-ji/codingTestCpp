// 누울 자리를 찾아라 - 1652
#include <iostream>
using namespace std;
char map[103][103];
int main(){
    int N;
    cin >> N;
    int rowCnt, colCnt;
    int rowSpace = 0;
    int colSpace = 0;
    
    for(int i = 0; i < N; i++){
        rowCnt = 0;
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == '.'){
                rowCnt++;
            }
            else{
                if(rowCnt >= 2){
                    rowSpace++;
                }
                rowCnt = 0;
            }
            if(j == N-1 && rowCnt >= 2){
                rowSpace++;
            }
        }
    }

    for(int i = 0; i < N; i++){
        colCnt = 0;
        for(int j = 0; j < N; j++){
            if(map[j][i] == '.'){
                colCnt++;
            }
            else{
                if(colCnt >= 2){
                    colSpace++;
                }
                colCnt = 0;
            }
            if(j == N-1 && colCnt >= 2){
                colSpace++;
            }
        }
    }
    cout << rowSpace << " " << colSpace;

}