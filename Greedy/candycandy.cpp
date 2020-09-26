// 캔디캔디 - 2878
#include <iostream>
#include <algorithm>
using namespace std;
int wantCandy[100000+2];
int main(){
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> wantCandy[i];
    }
    sort(wantCandy, wantCandy + n, greater<int>()); // 정렬하고 못받은만큼 분노 제곱해서 더하면 된다.
    long long angry = 0;
    int restCandy = m;
    for(int i = 0; i < n; i++){
        restCandy = restCandy - wantCandy[i];
        if(restCandy > 0){
            continue;
        }
        else{
            angry += restCandy * restCandy;
            restCandy = 0;
        }
    }
    cout << angry;
}