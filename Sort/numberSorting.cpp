// 수 정렬하기 - 2750
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> numberVec;
int main(){
    cin >> N;
    int number;
    while(N--){
        cin >> number;
        numberVec.push_back(number);
        sort(numberVec.begin(), numberVec.end());
    }
    for(int i = 0; i < numberVec.size(); i++){
        cout << numberVec[i] << "\n";
    }
}