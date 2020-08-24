// 1718번
#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;

    typedef pair<int, int> pair;
    pair homework[10]; 

    for(int i = 0; i < n; i++){
        scanf("%d %d", &homework[i].first, &homework[i].second);
    }
    sort(homework, homework + n);

    long long sum = 0;
    priority_queue<int> pq;
    for(int i = 1, j = 0; i <= homework[n-1].first; i++){
        while(j < n && homework[j].first >= i){
            pq.push(homework[j++].second);
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
    return 0;
}