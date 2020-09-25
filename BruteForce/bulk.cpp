// 덩치 - 7568
#include <iostream>
#include <utility>
using namespace std;

int main(){
    int n;
    pair<int, int> bulk[50];
    // 키. 몸무게 최대 50명
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> bulk[i].first >> bulk[i].second;
    }
    int rank = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        {
            if(bulk[i].first < bulk[j].first && bulk[i].second < bulk[j].second){
                rank++;
            }
        }
        cout << rank << " ";
        rank = 1;
    }
}