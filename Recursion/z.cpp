// Z - 1074번
// #include <iostream>
// #define MAX 32770
// using namespace std;

// int dist[MAX][MAX]; // int map[32770][32770] -> 32770 * 32770 너무 커서 메모리 초과!!
// int cnt = 1;
// int zCnt = 1;
// int zEnd;
// int xyEnd;
// int N, r, c;
// void func(int x, int y){
//     zCnt += 1;
//     if(zCnt == zEnd){
//         cout << dist[r][c] - 1;
//         return;
//     }// 새로운 z그리기
//     dist[x][y] = cnt;
//     cnt += 1;
//     dist[x][y+1] = cnt;
//     cnt +=1;
//     dist[x+1][y] = cnt;
//     cnt+=1;
//     dist[x+1][y+1] = cnt;
//     cnt+=1;
//     if(y+2 >= xyEnd){
//         func(x+2, 0);
//     }else{
//         func(x, y+2);
//     }
// }

// int getZEnd(){
//     int a = 1;
//     for(int i = 0; i < 2*N -1; i++){
//         a = a * 2; 
//     }
//     return a;
// }
// int getXYEnd(){
//     int a = 1;
//     for(int i = 0; i < N; i++){
//         a = a * 2;
//     }
//     return a;
// }


// int main(){
//     cin >> N >> r >> c;
//     zEnd = getZEnd();
//     xyEnd = getXYEnd();
//     func(0, 0);
// }
// --------------위에는 수정 전 코드-------------------//
#include <iostream>
using namespace std;

int func(int n, int r, int c){ // r, c를 방문하는 순서를 반환
    if(n == 0) return 0;
    int half = 1 << (n-1);
    if(r < half && c < half) return func(n-1, r, c); // 1번 사각형
    if(r < half && c >= half) return half * half  + func(n-1, r, c-half);  // 2번 사각형
    if(r >= half && c < half) return 2 * half * half + func(n-1, r-half, c); // 3번 사각형
    return 3 * half * half + func(n-1, r-half, c-half); // 4번 사각형
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}