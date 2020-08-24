#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> vt;

int main(){
    cin >> n;
    vt.push_back(0);

    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        cout <<"----------------------------"<<endl;
        cout << "num->" << num << "vt.back()->" << vt.back() << endl;
        if(num > vt.back()){
            vt.push_back(num);
        }
        else{
            vector<int> ::iterator iter = lower_bound(vt.begin(), vt.end(), num);
            int index = lower_bound(vt.begin(), vt.end(), num) - vt;
            cout << "index~~~~~~~~~~~~" << index << endl;
            vt[index] = num;
        }
        for(int i = 0; i < vt.size(); i++){
            cout << vt[i] << "  ";
        }
        cout << endl;
    }
    cout << vt.size() - 1 << endl;

}