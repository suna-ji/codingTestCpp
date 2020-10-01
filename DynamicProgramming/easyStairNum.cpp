// 쉬운 계단 수 - 10844
// 하나도 안쉬움..다시 풀어봐야함 ✍✍️
// memo[i][j] : 길이가 i일때, 마지막 계단이 j인 계단수의 개수
// 계단수는 이전 길이의 계단에서 어떤수로 끝나는지가 중요하다
// 그 어떤 숫자가 0인지 9인지! 그게 중요..
#include <iostream>
#define MAX 100 + 2
using namespace std;
int N; // 계단의 길이
long long memo[MAX][10];
int main(){
    cin >> N;
    for(int i = 1; i <= 9; i++){
        memo[1][i] = 1;
    }
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j <= 9; j++){
            if(j == 0){
                memo[i][j] = memo[i-1][1];
            } // 끝이 0이라는것 => 길이가 i-1인 계단 중 1로 끝났던 계단의 개수랑 같다 (왜냐면 1에서 빼서 나오는 경우밖에 없어서, 뭘 더해서 0이 될수는 없으니까)
            else if(j == 9){
                memo[i][j] = memo[i-1][8];
                // 길이 i-1인 계단 중 8로 끝났던 계단에서 1 더해서 나오는 경우밖에 없음
            }else{
                memo[i][j] = memo[i-1][j-1] + memo[i-1][j+1];
            }
            memo[i][j] = memo[i][j] % 1000000000;
        }
    }
    long long sum = 0;
    for(int i = 0; i <= 9; i++){
        sum += memo[N][i];
    }
    cout << sum % 1000000000;
}