//가능한 모든 열의 조합을 만든다
//각 열의 조합에 해당하는 튜플이 후보키가 될수 있는지 확인한다.
//각 조합에 해당하는 열을 더해 새로운 튜플을 만들어 그 튜플이 중복되는지 확인한다.
//만약에 중복되지 않는 후보키가 될수있다면, answer값을 ++해주고 
//해당 조합을 부분집합으로 갖는 조합들을 모두 제거하여 최소성을 만족하지 못하는 쌍을 제거한다.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> lis;

void func(int max, int current, string vec,int col,int value){
    if(max==current)
    {
        lis.push_back(vec);
        return;
    }
    for(int i=value+1;i<=col;i++){
        vec+=i-1+48;
        func(max,current+1,vec, col, i);
        vec=vec.substr(0,vec.size()-1);
    }
}

bool different(vector<string> str){
    sort(str.begin(),str.end());
    for(int i=0;i<str.size()-1;i++)
        if(str[i]==str[i+1])
            return false;
    return true;
}

bool issubstr(string Short, string Long){
    for(int i=0;i<Short.size();i++){
        bool flag=false;
        for(int j=0;j<Long.size();j++)
            if(Short[i]==Long[j])
                flag=true;
        if(flag==false)
            return false;
    }
    return true;
}


int solution(vector<vector<string>> relation) {
    int answer = 0;

    for(int i=1;i<=relation[0].size();i++)//1~모든열 조합
        func(i, 0, "", relation[0].size(), 0 );
    
    for(int i=0;i<lis.size();i++){//i번째 조합
        vector<string> tuple;
        for(int k=0;k<relation.size();k++)//아래로 k줄있음
        {
            string tmp="";
            for(int j=0;j<lis[i].size();j++)//의 각 원소들
                tmp+=relation[k][lis[i][j]-48];   
            tuple.push_back(tmp);
        }
        if(different(tuple)){
            answer++;
            for(int j=i+1;j<lis.size();j++){
                if(issubstr(lis[i],lis[j]))
                    lis[j]="";
            }
        }
    }
    return answer;
}
