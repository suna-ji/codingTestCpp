// 연습장
#include <stdio.h>
#include <iostream>

using namespace std;

int computers;
int connections;

int parent[10];

int Find(int x){

	if(x == parent[x]){
		return x;
	}
	else{
		int y = Find(parent[x]);
		parent[x] = y;
		return y;
	}

}

void Union(int x, int y){

	x = Find(x);
	y = Find(y);

	if(x!=y){
		parent[y] = x;
	}


}

int main() {

	scanf("%d", &computers);
	scanf("%d", &connections);

	// 초기화
	// 처음에는 각각 노드가 부모노드가 자기자신
	for(int i=0; i<=computers; i++){
		parent[i] = i;
	}

	int u,v;
	while(connections--){
		scanf("%d %d", &u, &v);

		Union(u,v);
	}

	// Root 노드가 1인 노드를 검색해서 cnt에 더해줌
	int cnt = 0;
	for(int i=2; i<=computers; i++){
		if(Find(1) == Find(i)) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}