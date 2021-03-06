// 부분 문자열 - 16916
#include <iostream>
#include <vector>
using namespace std;
// 문자열의 길이는 100만을 넘지 않는다 -> 시간 부족한가..? 
// char result[MAX];
// bool match;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     string baseStr, subStr;
//     cin >> baseStr >> subStr;
//     for(int i = 0; i < baseStr.length(); i++){
//         result[i] = baseStr[i];
//         if(result[i] == subStr[subStr.length()-1]){
//             if((i - subStr.length()) < 0){
//                 continue;
//             }
//             match = true;
//             for(int j = 0; j < subStr.length(); j++){
//                 //cout <<i-j <<"->"<<result[i-j] << subStr.length() - j - 1 << "->" <<subStr[subStr.length()-j-1] <<"\n";
//                 if(result[i-j] != subStr[subStr.length()-j-1]){
//                     match = false;
//                     break;
//                 }
//             }
//             if(match){
//                 break;
//             }
//         }
//     }
//     if(match){
//         cout << 1;
//     }else{
//         cout << 0;
//     }
// }
// 시간초과 뜸 -> kmp알고리즘 배우고 다시..
vector<int> makeTable(string subStr){
    int size = subStr.size();
    vector<int> table(size, 0);
    int j = 0;
    for(int i = 1; i < size; i++){
        while(j > 0 && subStr[i] != subStr[j]){
            j = table[j-1];
        }
        if(subStr[i] == subStr[j]){
            table[i] = ++j;
        }
    }
    return table;
}

void kmp(string baseStr, string subStr){
    vector<int> table = makeTable(subStr);
    int bSize = baseStr.size();
    int sSize = subStr.size();
    int j = 0; 
    for(int i = 0; i < bSize; i++){
        while(j > 0 && baseStr[i] != subStr[j]){
            j = table[j-1];
        }
        if(baseStr[i] == subStr[j]){
            if(j == sSize - 1){
                cout << 1 << "\n"; // 찾았다는 뜻
                return; // 다시 찾을필요 없어서 종료
            }
            else{
                j++;
            }
        }
    }
    cout << 0 << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string baseStr, subStr;
    cin >> baseStr >> subStr;
    kmp(baseStr, subStr);
}