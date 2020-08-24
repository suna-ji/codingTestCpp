#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n,l; // 물이 새는 위치, 테이프의 길이
    cin >> n >> l;

    vector<pair<double, double> > repairRange;
    int pos;
    double totalRepair;

    for(int i = 0; i < n; i++){
        cin >> pos;
        repairRange.push_back(make_pair(pos - 0.5, pos + 0.5));
    }
    sort(repairRange.begin(), repairRange.end());
    double temp = 1;
    int tapeNum = 0₩;
    if(n == 1){
        tapeNum = 1;
    }else{
        for(int i = 0; i < n-1; i++){
            if(repairRange[i].second == repairRange[i+1].first){
                temp++;
            }
            else{
                tapeNum += ceil(temp / l);
                temp = 1;
            }
            if(i == n-2){
                tapeNum += ceil(temp / l);
            }
        }
    }
    cout << tapeNum;
}