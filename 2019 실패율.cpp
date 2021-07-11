//직접 반복문을 돌면서 분자와 분모를 구한다.
//구한뒤에 compare함수를 분모/분자한 값으로 정의하여 sort를 수행한다. N까지만 바꿔야하므로 iterator를 사용한다
//정렬된 index를 n번째까지 출력한다.


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.second.second!=0&&b.second.second!=0&&
       (((double)a.second.first/a.second.second)>((double)b.second.first/b.second.second))){
        return true;
        }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<int,pair<int,int>>> list;//index, <분자,분모>
    
    for(int i=0;i<500;i++)
        list.push_back(make_pair(i+1,make_pair(0,0)));
    
    for(int i=0;i<stages.size();i++)
        for(int j=0;j<stages[i];j++){
            list[j].second.second++;
        }
    
    for(int i=0;i<stages.size();i++)
        list[stages[i]-1].second.first++;
    
    
    vector<pair<int,pair<int,int>>>::iterator iter=list.begin();
    for(int i=0;i<N;i++)
        iter++;
    
    stable_sort(list.begin(),iter,compare);
    
    for(int i=0;i<N;i++)
        if(list[i].first!=0)
            answer.push_back(list[i].first);
    
    return answer;
}
