// 1717번
#include <iostream>
#include <stdio.h>
using namespace std;

int parent[1000001];
int find(int x){
    if(x == parent[x]){
        return x;
    }else{
        int y = find(parent[x]);
        parent[x] = y;
        return y;
    }
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        parent[y] = x;
    }
}

int main(){
    int n;
    int m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }// 초기화 (모두 자기 자신으로 설정)
    int type, a, b;
    while(m--){
        scanf("%d %d %d", &type, &a, &b);
        if(type == 0){
            Union(a, b);
        }else{
            if(find(a)== find(b)) 
                printf("yes\n");
            else{
                printf("no\n");
            }
        }
    }

}