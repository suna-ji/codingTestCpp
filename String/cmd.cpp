// 명령 프롬프트 - 1032
#include <iostream>
using namespace std;
// 검색결과를 보고 패턴으로 뭘 쳐야 그 결과가 나오는지 출력하는 문제
// 패턴에는 "." "?" 만 가능
// 가능하면 ?를 적게 사용할 것
int main(){
    int N;
    cin >> N;
    string fileArr[50];
    for(int i = 0; i < N; i++){
        cin >> fileArr[i];
    }// 파일이름 입력
    string pattern = fileArr[0];
    for(int i = 0; i < fileArr[0].length(); i++){
        for(int j = 1; j < N; j++){
            if(fileArr[0][i] != fileArr[j][i]){
                pattern[i] = '?';
                break; // 만약 다르다면 그 아래 파일명은 패스하기 위해서 파일명의 개수 (N)이 2번째 for문으로 설정되어야함 
            }
        }
    }
    cout << pattern;
}