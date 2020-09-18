// 과제 - 13904
// 과제마다 점수있고 마감일이 지난 과제는 점수를 받을 수 없다.
// 점수의 최댓값 구하시오
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int dayArr[1002];
bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second; // p2(점수)를 기준으로 내림차순 정렬
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int> > vec;
    int N;
    cin >> N;
    int d, w; // 남은 일수, 점수

    for(int i = 0; i < N; i++){
        cin >> d >> w;
        vec.push_back(make_pair(d, w));
    }
    
    sort(vec.begin(), vec.end(), compare);

    for(int i = 0; i < vec.size(); i++){
        int day = vec[i].first;
        if(dayArr[vec[i].first] == 0){
            dayArr[vec[i].first] = vec[i].second;
        }
        else{
            while(day > 0){
                if(dayArr[day] == 0){
                    dayArr[day] = vec[i].second;
                    break;
                }
                day--;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < 1002; i++){
        sum += dayArr[i];
    }
    cout << sum;
}

