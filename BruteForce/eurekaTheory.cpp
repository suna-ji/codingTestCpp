// 유레카 이론 - 10448
// 중복조합...?
#include <iostream>
#include <cstring>
#define MAX 45
using namespace std;
int n;
int isEureka;
int selectArr[3];

void dfs(int idx, int cnt){
    if(cnt == 3){ // 3개 다 합쳤으면 
        int result = 0;
        for(int i = 0; i < 3; i++){
            result += (selectArr[i] *(selectArr[i] + 1) / 2);
        }
        if(result == n){
            isEureka = 1;
            return;
        }else{
            return;
        }
    }
    for(int i = idx; i < MAX; i++){
        if( (i * (i+1)/2) > n ) continue; // 삼각수가 n보다 크면 패스
        selectArr[cnt] = i;
        dfs(i, cnt + 1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        memset(selectArr, 0, sizeof(selectArr));
        isEureka = 0;
        dfs(1, 0);
        cout << isEureka << "\n";
    }
}
//-------------------------더 쉬운 코드----------------------------//
// 미리 삼각수를 만들고 3중 for문을 사용하여 삼각수 3개로 더해서 n이 되는지 판별
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> eureka;

// void preCalculate(){
//     int n = 1;
//     while((n) * (n+1)/2 < 1000){
//         eureka.push_back((n) * (n+1)/2 );
//         n++;
//     }
// }
// bool triangleSum(int total){
//     for(int i = 0; i < eureka.size(); i++){
//         for(int j = 0; j < eureka.size(); j++){
//             for(int k = 0; k < eureka.size(); k++){
//                 if(eureka[i] + eureka[j] + eureka[k] == total){
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }
// int main(){
//     int t;
//     cin >> t;

//     preCalculate(); // 삼각수 계산하고!

//     for(int i = 0; i < t; i++){
//         int total;
//         cin >> total;
//         cout << triangleSum(total) << "\n";
//     }
//     return;
// }