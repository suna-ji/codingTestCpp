// 수 묶기 - 1744번
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int N; // 수열 크기 10,000보다 작음
    cin >> N;
    vector<int> pNumber;
    vector<int> nNumber;
    int number;
    for(int i = 0; i < N; i++){
        cin >> number;
        if(number > 0){ // 0은 negative에 
            pNumber.push_back(number);
        }else{
            nNumber.push_back(number);
        }
    }// 입력끝
    // 음수벡터는 오름차순으로 정렬
    sort(nNumber.begin(), nNumber.end()); // default
    // 양수벡터는 내림차순으로 정렬
    sort(pNumber.begin(), pNumber.end(), greater<int>());
    int result = 0;
    for(int i = 0; i < nNumber.size(); i+=2){
        if(i+1 == nNumber.size()){
            result += nNumber[i];
        }else{
            result += (nNumber[i] * nNumber[i+1]);
        }
    }
    for(int i = 0; i < pNumber.size(); i+=2){
        if(i+1 == pNumber.size()){
            result += pNumber[i];
        }else{
            if(pNumber[i] * pNumber[i+1] > pNumber[i] + pNumber[i+1]){
                result += (pNumber[i] * pNumber[i+1]);
            }else{
                result += (pNumber[i] + pNumber[i+1]);
            }
            
        }
    }
    cout << result << endl;
}