//map에 id를 key 닉네임을 value로 한다
//첫 for문에서 만약에 Enter라면 이미 저장된 key인지를 확인하여 새로 넣던지 대입하던지 한다.
//change라면 value를 바꿔준다.
//두번째 for문에서 Enter라면 해당 uid에 해당되는 닉네임+들어왔습니다, leave라면 uid에 해당되는 닉네임+나갔습니다를 출력한다.

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string key, value;
    int tmp1,tmp2;
    
    map<string, string> lis; //id, nickname
    for(int i=0;i<record.size();i++){
        tmp1=0; tmp2=0;
        if(record[i][0]=='E'){
            for(int j=0;j<record[i].size();j++){
                if(record[i][j]==' '&&tmp1==0)
                    tmp1=j+1;
                else if(record[i][j]==' '&&tmp1!=0){
                    tmp2=j+1; 
                    break;
                }
            }
            key=record[i].substr(tmp1,tmp2-tmp1);
            value=record[i].substr(tmp2);

            if(lis.find(key)!=lis.end())//있으면   
                lis[key]=value;
            else
                lis.insert(make_pair(key, value));
        }
        else if(record[i][0]=='C'){
            for(int j=0;j<record[i].size();j++){
                if(record[i][j]==' '&&tmp1==0)
                    tmp1=j+1;
                else if(record[i][j]==' '&&tmp1!=0){
                    tmp2=j+1; 
                    break;
                }
            }
            key=record[i].substr(tmp1,tmp2-tmp1);
            value=record[i].substr(tmp2);
            lis[key]=value;
        }
    }
    
    for(int i=0;i<record.size();i++){
        tmp1=0;
        tmp2=0;
        if(record[i][0]=='E')
        {

            for(int j=0;j<record[i].size();j++){
                if(record[i][j]==' '&&tmp1==0)
                    tmp1=j+1;
                else if(record[i][j]==' '&&tmp1!=0){
                    tmp2=j+1; 
                    break;
                }
            }
            key=record[i].substr(tmp1,tmp2-tmp1);
            answer.push_back(lis[key]+"님이 들어왔습니다.");
        }  
        else if(record[i][0]=='L'){
            for(int j=0;j<record[i].size();j++){
                if(record[i][j]==' '){
                    tmp1=j+1;
                    break;
                }
            }
            key=record[i].substr(tmp1)+' ';
            answer.push_back(lis[key]+"님이 나갔습니다.");
        }
    }
    return answer;
}
