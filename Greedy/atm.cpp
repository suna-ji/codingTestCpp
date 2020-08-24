#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int n, p;
    cin >> n;
    int time[n];
    for(int i = 0; i < n; i++){
        cin >> p;
        time[i] = p;
    }
    sort(time, time+n);
    for(int i = 0; i < n; i++){
        cout << time[i] << endl;
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            sum += time[j];
        }
    }
    cout << sum;
    return 0;
}
