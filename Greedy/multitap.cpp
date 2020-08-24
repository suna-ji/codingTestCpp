#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int mNum;
    int sNum;
    cin >> mNum >> sNum;
    vector<int> scheduleVec;
    int multitap[100] = {0};

    int schedule;
    int sum = 0;
    
    for(int i = 0; i < sNum; i++){
        cin >> schedule;
        scheduleVec.push_back(schedule);
    }

    for(int i = 0; i < sNum; i++){
        int *index = find(multitap, multitap + mNum, scheduleVec[i]);
        int *isEmpty = find(multitap, multitap + mNum, 0);
        if(index != multitap + mNum){ // 기기가 이미 꽂혀있음
            continue;
        }
        if(isEmpty != multitap + mNum){  // 비어있음
            multitap[isEmpty - multitap] = scheduleVec[i]; 
        } 
        if(isEmpty == multitap + mNum){ 
            sum++;
            int max = -1;
            int popIndex;
            for(int j = 0; j < mNum; j++){
                vector<int>::iterator iter = find(scheduleVec.begin() + i + 1, scheduleVec.end(), multitap[j]);
                if(iter == scheduleVec.end()){
                    popIndex = j;
                    break;
                } 
                else{
                    if(max < iter- scheduleVec.begin()){
                        max = iter-scheduleVec.begin();
                    }
                }
            }
            if(!popIndex){
                int *p = find(multitap, multitap + mNum, scheduleVec[max]);
                popIndex = p - multitap;
            }
            multitap[popIndex] = scheduleVec[i];
        }
    }
    cout << sum;
}