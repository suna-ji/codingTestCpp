// 2606번
#include <stdio.h>
#include <iostream>

using namespace std;
int parent[101];

int Find(int x){
    if(x == parent[x]){
        return x;
    }else{
        int y = Find(parent[x]);
        parent[x] = y;
        return y;
    }
}// x로 들어온 원소의 root노드를 반환

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x!=y){
        parent[y] = x;
    }// 서로의 root가 다르면 

}// x와 y를 합치는 함수로, y의 root노드를 x로 설정


int main(){
    int computers;
    int networks;
    
    scanf("%d", &computers);
    scanf("%d", &networks);

    for(int i = 0; i<= computers; i++){
        parent[i] = i;
    }
    int u,v;
    while(networks--){
        scanf("%d %d", &u, &v);
        Union(u, v);
    }
    int sum = 0;
    // 1이 루트인 모든 노드의 갯수 리턴
    for(int i = 2; i <= computers; i++){
        if(Find(1) == Find(i)) sum++;
    }
    cout << sum;
    return 0;
}
