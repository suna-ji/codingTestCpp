// 팰린드롬? - 10942
// 거꾸로 읽어도 같은거
// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     int a;
//     for(int i = 1; i <= n; i++){
//         cin >> a;
//         numbers[i] = a;
//     }
//     int QNum;
//     cin >> QNum;
//     int s, e;

//     while(QNum--){
//         cin >> s;
//         cin >> e;
       
//         int f;
//         int stop = false;
//         if(s-e+1 % 2 == 0){
//             f = e / 2 + 1;
//         }// 짝수면
//         else{
//             f = e / 2;
//         }// 홀수이면
//         for(int i = s; i <= f; i++){
//             if(numbers[i] != numbers[e-i+1]){
//                 cout << 0 <<"\n";
//                 stop = true;
//                 break;
//             }
//         }
//         if(!stop){
//             cout << "1" << "\n";
//         }   
//     }
    
// }
// DP하는날 다시한다.
// 0.5초라는 시간제한이 있어서 DP로
// 점화식
//1 memo[s][s] = 1 // (문자열 길이 1이면 무조건 팰린드롬)(여기가 시작지점 각 원소 하나 하나는 팰린드론 -> 그럼 그 밖에 2개도 팰린드롬인지 확인하면 그 문자열은 팰린드롬)
//2 memo[s][s+d] = Arr[s] == Arr[s+d];
//3 memo[s][s+d] = memo[s+1][s+d-1] ? Arr[s] == Arr[s+d] : 0; 
#include <iostream>
#include <vector> 
using namespace std;

int N, M;
vector<int> Arr;
vector<vector<int> > memo;

int func(int s, int e){
    if(s == e){ // s == e가 baseCondition (즉, 각 요소는 다 팰린드롬)
        memo[s][e] = 1; 
        return 1;
    }
    else if(s + 1 == e){ // s와 e가 1개차이 (즉, 나란하게 있는 2개 원소를 비교)
        return memo[s][e] = Arr[s] == Arr[e];
    }else{ // 3개 이상 -> 여기서부터 DP
        if(memo[s+1][e-1] == -1){ // 입력으로 들어온 s와 e의 속 -> s+1, e-1이 비어있다면! 속부터 넣어주고
            memo[s+1][e-1] = func(s+1, e-1);
        }
        //비어있지 않다면 그 2개만 비교하면 되겠지?
        return memo[s][e] = memo[s+1][e-1] ? Arr[s] == Arr[e] : 0;
        // memo[s+1][e-1]의 결과를 보고 이게 팰린드롬 이라면 Arr[s] == Arr[e]인지 확인해서 결과로 넣어주고
        // 속에서부터 팰린드롬이 아니였으면 그냥 0리턴
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    Arr.push_back(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num;
        Arr.push_back(num);
    }
    cin >> M;
    memo.resize(N+1, vector<int>(N+1, -1));
    int ts, te;
    while(M--){
        cin >> ts >> te;
        if(memo[ts][te] == -1){
            memo[ts][te] = func(ts, te);
        }// 중복계산을 막기위한 장치
        cout << memo[ts][te] << "\n";
    }
}