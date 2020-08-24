#include <iostream>
#include <vector>
#include <utility> 
#include <string>
using namespace std;

int main(){
    int dnaNum, dnaLength;
    cin >> dnaNum >> dnaLength;
    string dna;
    
    vector<string> dnaVec;
    vector<pair<int,char> > HammingVec;
    string ans = "";
    int totalHamming = 0;

    HammingVec.push_back(make_pair(0, 'A'));
    HammingVec.push_back(make_pair(0, 'T'));
    HammingVec.push_back(make_pair(0, 'G'));
    HammingVec.push_back(make_pair(0, 'C'));
   
    for(int i = 0; i < dnaNum; i++){
        cin >> dna;
        dnaVec.push_back(dna);
    }

    for(int i = 0; i < dnaLength; i++){
        for(int j = 0; j < dnaNum; j++){
            if(dnaVec[j][i] != 'A'){
                HammingVec[0].first++;
            }
            if(dnaVec[j][i] != 'T'){
                HammingVec[1].first++;
            }
            if(dnaVec[j][i] != 'G'){
                HammingVec[2].first++;
            }
            if(dnaVec[j][i] != 'C'){
                HammingVec[3].first++;
            }
        }
        sort(HammingVec.begin(), HammingVec.end());
        totalHamming += HammingVec[0].first;
        ans += HammingVec[0].second;
       
        HammingVec[0].first = 0;
        HammingVec[0].second = 'A'; 
        HammingVec[1].first = 0;
        HammingVec[1].second = 'T'; 
        HammingVec[2].first = 0; 
        HammingVec[2].second = 'G'; 
        HammingVec[3].first = 0;
        HammingVec[3].second = 'C'; 
    }
    cout << ans << endl;
    cout << totalHamming << endl;
}