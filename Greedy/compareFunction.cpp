bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first){
        return p1.second > p2.second; // first가 동일하다면 second를 기준으로 내림차순 정렬
    }
    return p1.first < p2.first;// 우선 first 기준 오름차순으로 정렬
};

 sort(vec.begin(), vec.end(), compare);