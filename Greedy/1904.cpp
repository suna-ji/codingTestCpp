#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        cin >> n;
        int sum = n;
        vector<pair<int,int> > v; // v(n)으로 하면 다 0으로 초기화되서 오류났음
        int a, b;
        for(int j = 0; j < n; j++){
            cin >> a >> b;
            v.push_back(make_pair(a , b));
        }
        
        (v.begin(), v.end());
        // 정렬을 했기 때문에 2번째부터..!
        // 자신위의 지원자들의 면접등수보다 크다면 탈락 아 근데 2중루프 안하고 어떻게 하냐면 min담아두고
        int min = v[0].second;
        for(int j = 1; j < n; j++){
            if(min > v[j].second){
                min = v[j].second;
            }
            if(min < v[j].second){ // 탈락
                sum--;
            }
        } 
        cout << sum << endl;
    }
}
