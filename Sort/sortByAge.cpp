// 나이순 정렬 - 10814
// 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순으로 정렬
// 나이와 이름이 가입한 순서대로 주어진다.
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<pair<int, int>, string> > memberInfo; // 나이, 가입순서, 이름
bool compare(pair<pair<int, int>, string> p1, pair<pair<int, int>, string> p2){
    if(p1.first.first == p2.first.first){ // 나이가 같다면 가입년도 순으로 오름차순 정렬
        return p1.first.second < p2.first.second; // first가 동일하다면 second를 기준으로 오름차순 정렬
    }
    return p1.first.first < p2.first.first;// 우선 first 기준 오름차순으로 정렬
}

int main(){
    cin >> N;
    int age;
    string name;
    for(int i = 1; i <= N; i++){
        cin >> age >> name;
        memberInfo.push_back(make_pair(make_pair(age, i), name));
    }
    sort(memberInfo.begin(), memberInfo.end(), compare);

    for(int i = 0; i < N; i++){
        cout << memberInfo[i].first.first << " " << memberInfo[i].second << "\n";
    }
}