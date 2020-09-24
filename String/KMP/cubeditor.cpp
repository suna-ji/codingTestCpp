// Cubeditor - 1701
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> makeTable(string subStr){
    int subStrSize = subStr.size();
    vector<int> table(subStrSize, 0);
    int j = 0;
    for(int i = 1; i < subStrSize; i++){
        while(j > 0 && subStr[i] != subStr[j]){
            j = table[j-1];
        }
        if(subStr[i] == subStr[j]){
            table[i] = ++j;
        }
    }
    return table;
}

int main(){
    string baseStr;
    cin >> baseStr;
    int baseStrSize = baseStr.size();
    int result = 0;
    for (int i = 0; i < baseStrSize; i++)
    {
        string subStr = baseStr.substr(i, baseStrSize); 
        vector<int> table = makeTable(subStr);
        sort(table.begin(), table.end(), greater<int>()); // 내림차순 
        result = max(result, table[0]); 
    }
    cout << result << "\n";
}