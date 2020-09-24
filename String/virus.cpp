// 바이러스 - 7575
#include <iostream>
#include <vector>
using namespace std;
int code[100][1000];
vector<int> makeTable(string str){
    int size = str.size();
    vector<int> table(size, 0);
    int j = 0;
    for(int i = 1; i < size; i++){
        while(j > 0 && str[i] != str[j]){
            j = table[j-1];
        }
        if(str[i] == str[j]){
            table[i] = j++;
        }
    }
    return table;
}
int kmp(string base, string sub){
    int baseS = base.size();
    int subS = sub.size();
    vector<int> table = makeTable(sub);
    int j = 0;
    for(int i = 0; i < baseS; i++){
        while(j > 0 && base[i] != sub[j]){
            j = table[j-1];
        }
        if(base[i] == sub[j]){
            if(i == subS - 1){
                // j = table[j]; 또 찾고싶다면
                return 1;
            }else{
                j++;
            }
        }
    }
    return 0;
}
int main(){
    int n, k;
    cin >> n >> k;
    int l;
    int idx = 0;
    while(n--){
        cin >> l;
        for(int i = 0; i < l; i++){
            cin >> code[idx][i];
        }
        idx++;
    }
    
    int size = code[0].size();
    for(int i = 0; i < size-k; i++){
        string subStr = code[0].subStr(i, k);
        cout << subStr<<"\n";
        int isYes = true;
        for(int j = 1; j < n; i++){ // 나머지 줄에 대해서
            if(!kmp(code[j],subStr)){
                isYes = false;
            }
        }
    }
    if(isYes){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }
}
// 실패