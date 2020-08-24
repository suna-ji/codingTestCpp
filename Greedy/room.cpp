#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
};

int main(){
    int n, ans, s, e;
    ans = 1;
    int i = 0;
    int j = 1;
    cin >> n;
    vector<pair<int, int> > mettings;
    for(int i = 0; i < n; i++){
        cin >> s >> e;
        mettings.push_back(make_pair(s,e));
    }
    sort(mettings.begin(), mettings.end(), compare);
    for(int a = 0; a < n; a++){
        if(mettings[i].second > mettings[i+j].first){
            j++;
            continue; 
        }else{
            i = i+j;
            j = 1;
            ans++;
        }
    }
    cout << ans;
}

