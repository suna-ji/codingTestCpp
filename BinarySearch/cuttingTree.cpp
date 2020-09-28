// 나무 자르기 - 2805
// 모든 높이에 대해서 잘라보면 시간복잡도 O(N * M)
// 자를 높이를 이분탐색을 통해 
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000+3
using namespace std;
int n; // 나무의 개수
long long m; // 필요한 나무의 높이
long long tree[MAX];
//(1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    long long low = 1;
    long long high = 0;

    for(int i = 0; i < n; i++){ // 나무 길이 입력
        cin >> tree[i];
        high = max(high, tree[i]);
    }
    long long result = 0;
    while(low <= high){
        long long cuttingHeight = (low + high) / 2;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(tree[i] > cuttingHeight){
                sum += (tree[i] - cuttingHeight);
            }   
        }
        if(sum >= m){ // 필요한 나무 양보다 잘린 나무가 많음 -> 높더 높이를 높여서 덜 잘라보자
            result = max(result, cuttingHeight);
            low = cuttingHeight + 1;
        }else{
            high = cuttingHeight - 1;
        }
    }
    cout << result << "\n";
}
// ----------------------------3학년 1학기 알고리즘 과제로 풀었던 코드---------------------------- //
/*ID: 2016112128 NAME: Áö¼±¾Æ*/
#include <iostream>
#include <algorithm>
using namespace std;
int bisearch(struct Point2*a, int n,int k);
struct Point2 {
	int key;
	int value;
};
int main()
{
	int tree_n, tree_h;
	cin >> tree_n;
	cin>>tree_h;

	int *tree = new int[tree_n]; // 동적할당 안하고 전역변수에 MAX크기 넣어줘도 될듯!
	for (int i = 0; i < tree_n; i++)
		cin >> tree[i];
	
	int Temp = tree[0];
	for (int i = 1; i < tree_n; i++)
	{
		if (Temp < tree[i]) Temp = tree[i];
	}
    // max로 최대값 찾으면 될듯
    // temp말고 다른 변수명 썼으면 더 좋았을 것 같다	
	
	int size = Temp + 1;
	struct Point2 *bi_Arr = new struct Point2[size];

	bi_Arr[0].key = 0;
	bi_Arr[0].value = 10000;
	for (int i = 1; i <= Temp; i++)
	{
		int sum = 0;
		for (int j = 0; j < tree_n; j++)
		{
			if (tree[j] < i)
				sum += 0; // 필요없는 코드
			else
			sum += (tree[j] - i);
		}
		bi_Arr[i].key = i;
		bi_Arr[i].value = sum; // ..?
	}
	
	int k;
	int v;
	for (int j = 0; j <= Temp; j++)
	{
		for (int i = 0; i < Temp; i++)
		{
			if (bi_Arr[i].value > bi_Arr[i + 1].value)
			{
				v = bi_Arr[i].value;
				bi_Arr[i].value = bi_Arr[i + 1].value;
				bi_Arr[i + 1].value = v;
				k = bi_Arr[i].key;
				bi_Arr[i].key = bi_Arr[i + 1].key;
				bi_Arr[i + 1].key = k;
			}
		}
	}
	cout<< bisearch(bi_Arr,Temp,tree_h);
}

int bisearch(struct Point2 *a,int n,int k)
{
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (k == a[mid].value) return a[mid].key;
		if (k < a[mid].value) high = mid - 1;
		if (k > a[mid].value) low = mid + 1;
	}
	return 0;
}
