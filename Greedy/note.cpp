// 연습장
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
 
typedef pair<int, int> p;
p jew[300000];
int bag[300000];
int n, k, m, v, c, i, j;
 
int main() {
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d %d", &jew[i].first, &jew[i].second);
    }
    for (i = 0; i < k; ++i)
        scanf("%d", &bag[i]);
 
    sort(jew, jew + n);
    sort(bag, bag + k);
 
    long long sum = 0;
    priority_queue<int> pq;
    for (i = 0, j = 0; i < k; ++i) {
        while (j < n && jew[j].first <= bag[i])
            pq.push(jew[j++].second);
        
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    printf("%lld", sum);
    return 0;
}
