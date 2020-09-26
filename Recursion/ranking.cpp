// 등수 매기기 - 2012
#include <iostream>
#include <algorithm>
using namespace std;
// 1등부터 N등까지 동석차없이 점수를 매겨야한다.
// A로 예상했는데 B가되면 불만도는 |A-B|
// 모든 사람의 불만도 총합이 최소가 되도록..
long long predictRank[500000+2]; // 사람은 500000명까지
long long ranking[500000+2]; // 사람은 500000명까지
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     int dissatisfaction = 0;
//     for(int i = 0; i < n; i++){
//         cin >> predictRank[i];
//     }
//     for(int i = 0; i < n; i++){
//         int predict = predictRank[i];
//         if(ranking[predict] == 0){
//             ranking[predict] = 1;
//         }// 아직 그 등수 비어있음 -> 넣어준다.
//         else{
//             int downIdx, upIdx;
//             int diffDown = 99999;
//             int diffUp = 99999;
//             for(int j = predict+1; j <= n; j++){
//                 if(ranking[j] == 0){
//                     downIdx = j;
//                     diffDown = abs(j - predict);
//                     break;
//                 }
//             }
//             for(int j = predict-1; j > 0; j--){
//                 if(ranking[j] == 0){
//                     upIdx = j;
//                     diffUp = abs(j - predict);
//                     break;
//                 }
//             }
//             if(diffDown > diffUp){ 
//                 ranking[upIdx] = 1;
//                 dissatisfaction += diffUp;
//             }else{
//                 ranking[downIdx] = 1;
//                 dissatisfaction += diffDown;
//             }
//             // predictRank에서 n까지 하나씩 내려가
//             // predictRank에서 1까지 하나씩 올라가
//             // 둘중에 낮은거 골라서 넣어
//         }
//     }
//     cout << dissatisfaction;
// }
// 위에 코드는 시간초과 -> 정렬하고 불만도 더해가는 식으로 해주자
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     int dissatisfaction = 0;
//     for(int i = 0; i < n; i++){
//         cin >> predictRank[i];
//     }
//     sort(predictRank, predictRank + n);
//     for(int i = 0; i < n; i++){
//         int predict = predictRank[i];
//         if(ranking[predict] == 0){
//             ranking[predict] = 1;
//         }// 아직 그 등수 비어있음 -> 넣어준다.
//         else{
//             int downIdx, diffDown;
//             for(int j = predict+1; j <= n; j++){
//                 if(ranking[j] == 0){
//                     downIdx = j;
//                     diffDown = abs(j - predict);
//                     break;
//                 }
//             }
//             ranking[downIdx] = 1;
//             dissatisfaction += diffDown;
//         }
//     }
//     cout << dissatisfaction;
// }
// 이것도 시간초과 나는데 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long dissatisfaction = 0; // 사람 많아서 long long 인거 주의..
    for(int i = 0; i < n; i++){
        cin >> predictRank[i];
    }
    sort(predictRank, predictRank + n); // 정렬하고 나서 그냥 차이만 비교해주면 됨..
    for(int i = 0; i < n; i++){
        dissatisfaction += abs((i+1) - predictRank[i]);
    }
    cout << dissatisfaction;
}