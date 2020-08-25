#include <iostream>
#include <algorithm>
using namespace std;

int parent[100001];
int find(int x){
    if(x == parent[x])
        return x;
    else{
        int y = find(parent(x));
        parent[x] = y;
        return y;
    }
}

void untie(int x, int y){
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main(){

    scanf("%d", &g); // 게이트 수
    scanf("%d", &p); // 비행기 수 

    for(int i = 0; i <= g; ++i){
        parent[i] = i;
    }

    int sum = 0;

    for(int i = 1; i <= p; i++){
        scanf("%d", &a);
        int emptyGate = find(a);
        if(a == 0){
            break;
        }else{
            untie(emptyGate, emptyGate-1);
            sum++
        }
    }
    printf("%d", sum);
}
// 10775번 // 그리디 // disjoint-Set 