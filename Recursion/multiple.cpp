// 곱셈 - 1629
#include <iostream>
using namespace std;
// using ll = long long;

long long POW(long long a, long long b, long long m){
    if(b == 1) return a % m;
    long long val = POW(a, b/2, m);
    val = val * val % m;
    if(b % 2 == 0) return val; // b가 짝수면 그냥 리턴
    return val * a % m; // 아니면 한번 더 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
}