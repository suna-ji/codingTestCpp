// 암호만들기 - 1759
// 재귀함수 조건 만드는게 어려웠음..
// sort함수 안쓰고 재귀함수에서 비교하려고 했는데 블로그 보니까 sort함수 써야함
// 🤸‍♂️ 다시 풀어볼것! 🤸‍♂️
#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char arr[15];
int vowels; // 모음
int consonants; // 자음

void func(int idx, int cnt, string result, int vowels, int consonants){
    if(cnt == l){ // 암호길이 충족
        if(vowels >= 1 && consonants >=2){
            cout << result <<"\n";
        }
        return;//만약 위의 조건을 만족하지 않더라도 return해야함
    }
    if(idx == c){ // 모든 요소 돌았음
        return;
    }
    if(arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i' || arr[idx] == 'o' || arr[idx] == 'u'){
        func(idx+1, cnt+1, result+arr[idx], vowels+1, consonants); // 선택한 알파벳이 모음 (cnt + 1)
    }else{
        func(idx+1, cnt+1, result+arr[idx], vowels, consonants+1); // 선택한 알파벳이 자음 (cnt + 1)
    }
    func(idx+1, cnt, result, vowels, consonants); //해당 알파벳을 선택하지 않을 경우 (cnt 그대로)
}

int main(){
    cin >> l >> c;
    for(int i = 0; i < c; i++){
        cin >> arr[i];
    }
    sort(arr, arr+c); // 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열
    func(0, 0, "", 0, 0);
}