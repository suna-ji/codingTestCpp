#include <string>
#include <deque>
#include <vector>
#include <iostream>
using namespace std;
deque<int> dq;

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    vector<int> temp;
    for(int i = 0; i < ball.size(); i++){
        dq.push_back(ball[i]);
    }
    for(int i = 0; i < order.size(); i++){
        if(!dq.empty()){
            if(dq.front() == order[i]){
                cout << dq.front() << "프론트에서 뺌" << "\n";
                answer.push_back(dq.front());
                dq.pop_front();
            }
            if(dq.back() == order[i]){
                cout << dq.back() << "백에서 뺌" <<"\n";
                answer.push_back(dq.back());
                dq.pop_back();
            }
            else{
                cout << order[i]<< "temp에 넣음"<< "\n";
                temp.push_back(order[i]);
            }
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    if(temp[i] == dq.back()){
                        cout << dq.back()<< "temp의 백에서 뺌" << "\n";
                        temp.erase(temp.begin()+i);
                        answer.push_back(dq.back());
                        dq.pop_back();
                    }
                    if(temp[i] == dq.front()){
                        cout << dq.front() << "temp의 백에서 뺌" << "\n";
                        temp.erase(temp.begin()+i);
                        answer.push_back(dq.front());
                        dq.pop_front();
                    }
                }
            }
        }
    }
    return answer;
}


#include <string>
#include <deque>
#include <vector>
#include <iostream>
using namespace std;
deque<int> dq;

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    vector<int> temp;
    for(int i = 0; i < ball.size(); i++){
        dq.push_back(ball[i]);
    }
    int a = 0;
    while(!dq.empty()){
        if(!temp.empty()){
            for(int i = 0; i < temp.size(); i++){
                if(temp[i] == dq.back()){
                    cout << dq.back()<< "temp의 백에서 뺌" << "\n";
                    temp.erase(temp.begin()+i);
                    answer.push_back(dq.back());
                    dq.pop_back();
                }
                if(temp[i] == dq.front()){
                    cout << dq.front() << "temp의 프론트에서 뺌" << "\n";
                    temp.erase(temp.begin()+i);
                    answer.push_back(dq.front());
                    dq.pop_front();
                }
            }
            if(dq.front() == order[a]){
                cout << dq.front() << "프론트에서 뺌" << "\n";
                answer.push_back(dq.front());
                dq.pop_front();
                a++;
            }
            else if(dq.back() == order[a]){
                cout << dq.back() << "백에서 뺌" <<"\n";
                answer.push_back(dq.back());
                dq.pop_back();
                a++;
            }
            else{
                cout << order[a]<< "temp에 넣음"<< "\n";
                temp.push_back(order[a]);
                a++;
            }   
        }
    }
    return answer;
}