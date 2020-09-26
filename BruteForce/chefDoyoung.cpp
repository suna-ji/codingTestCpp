// 도영이가 만든 맛있는 음식 - 2961
// 조합(중복 x)
#include <iostream>
#include <utility> // pair
#include <algorithm>
using namespace std;
int n;
int sour[10];
int bitter[10];
pair<int, int> ingredients[10];
int selectedArr[10];
int selected[10];
int minDifference = 99999999;
void dfs(int idx, int cnt){
    int s = 1; // sour는 곱하기라서 1로 해야함 ㅠ.ㅠ
    int b = 0;
    int diffrence;
    if(cnt >= 1){
        for(int i = 0; i < cnt; i++){
            s *= ingredients[selectedArr[i]].first;
            b += ingredients[selectedArr[i]].second;
        }
        diffrence = abs(s - b);
        minDifference = min(minDifference, diffrence);
    }// 적어도 재료는 1개 이상!
    // 그리고 위의 if문에 return하면 1개인 경우만 구함
    for(int i = idx; i < n; i++){
        if(selected[i] == true) continue;
        selected[i] = true;
        selectedArr[cnt] = i;
        dfs(i, cnt+1);
        selected[i] = false;
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ingredients[i].first >> ingredients[i].second;
    }// 신맛 쓴맛 재료배열에 pair로 담기
    dfs(0, 0);
    cout << minDifference << "\n";
}