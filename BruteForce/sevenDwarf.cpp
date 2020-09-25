// 일곱 난쟁이 - 2309
// 일곱난쟁이의 키 합이 100임
// 9명의 난쟁이의 키를 보고 일곱 난쟁이를 찾아라
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int height[9];
    int sum = 0;
    for(int i = 0; i < 9; i++){
        cin >> height[i];
        sum += height[i];
    }
    int lier1, lier2;
    int isStop = false;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(100 == sum - height[i] - height[j] && i != j){
                height[i] = -1;
                height[j] = -1;
                isStop = true;
                break;
            }
        }
        if(isStop) break;
    }
    sort(height, height+9);
    for(int i = 2; i < 9; i++){
        cout << height[i] << "\n";
    }
}