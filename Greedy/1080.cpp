#include <iostream>
#include <vector>
using namespace std;

int isSame(int n, int m, vector<string> a, vector<string> b){
    int returnValue = 1;
    bool flag = true;
    for(int i = 0; (i < n && flag); i++){
        for(int j = 0; (j < m && flag); j++){
            if(a[i][j] != b[i][j]){
                returnValue = 0;
                flag = false;
                break;
            }
        }
    }
    return returnValue;
}
vector<string> calc(int x, int y, vector<string> vec){
    for(int i = x; i < x+3; i++){
        for(int j = y; j < y+3; j++){
            if(vec[i][j] == '1'){
                vec[i][j] = '0';
            }
            else{
                vec[i][j] = '1';
            }
        }
    }
    return vec;
}

int main(){
    int n,m;
    cin >> n >> m;
    bool isValid = true;
    vector<string> a;
    vector<string> b;
    if(n < 3 || m < 3){
       isValid = false;
    }
    string value;
    for(int i = 0; i < n; i++){
        cin >> value;
        a.push_back(value);
    }

    for(int i = 0; i < n; i++){
        cin >> value;
        b.push_back(value);
    }
    int sum = 0;
    bool same = true;
    bool flag = true;
    
    for(int i = 0; (i <  n - 2) && flag; i++){
        for(int j = 0; (j <  m- 2) && flag; j++){
            if((a[i][j]-'0') != (b[i][j]-'0')){ // 둘이 다르면
                same = false;
                sum++;
                a = calc(i, j, a);
                if(isSame(n,m,a,b)){ 
                    flag = false;
                }
            }
        }
    }

    if((same == false && flag == true) || !isValid){ // 끝까지 했는데 같지 않거나 애초에 3이하로 입력값이 들어옴
        cout << -1;
    }else{
        cout << sum;
    }  
   
}