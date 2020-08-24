#include <iostream>
#include <vector>
#include <cmath> // 절대값
#include <algorithm> // min함수
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    int appleNum;
    cin >> appleNum;
    
    int sum = 0;
    int pos;
    vector<int> posVec;
    posVec.push_back(1);
    int coverStart, coverEnd;
    for(int i = 0; i < appleNum; i++){
        cin >> pos;
        if(pos- m +1 <= 0){
            coverStart = 1;
        }else{
            coverStart = pos - m+ 1;
        }
        coverEnd = pos;
        cout << endl;
        cout << "pos" << pos << "coverStart" << coverStart << "coverEnd" << coverEnd << "posVec[i]" << posVec[i] << endl;
        if(posVec[i] >= coverStart && posVec[i] <= coverEnd){ //현재 위치가 바구니 커버 범위에 들어온다면 다음위치도 현재와 같게 설정하고 sum은 패스
            posVec.push_back(posVec[i]);
        }else{// 아니면 최소로 이동시키고 sum에 더해줘 

            if(posVec[i] < coverStart){ // 내가 왼쪽에 -> coverStart로 이동 // 내가 오른쪽에 ->  coverEnd
                cout << "coverStart지점으로 이동" << endl;
                sum += coverStart - posVec[i];
                posVec.push_back(coverStart);
            }else{
                cout << "coverEnd지점으로 이동" << endl;
                sum += posVec[i] - coverEnd;
                posVec.push_back(coverEnd);
            } 
        }
        cout << "sum->" << sum;
    }
    // cout << sum;
}