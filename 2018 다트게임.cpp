#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int tmp1=0,tmp2=0;//tmp1이 현재점수, tmp2가 이전점수
    int i=0;
    
    for(;i<dartResult.size();i++){
        if(dartResult[i]=='1'&&i<dartResult.size()-1 && dartResult[i+1]=='0'){
            answer+=tmp2;
            tmp2=tmp1;
            tmp1=10;
            i++;
        }
        else if(dartResult[i]>='0'&&dartResult[i]<='9'){
            answer+=tmp2;
            tmp2=tmp1;
            tmp1=dartResult[i]-48;
        }
        else if(dartResult[i]=='D')
            tmp1=tmp1*tmp1;
        else if(dartResult[i]=='T')
            tmp1=tmp1*tmp1*tmp1;
        else if(dartResult[i]=='*'){
            tmp1*=2;
            tmp2*=2;
        }
        else if(dartResult[i]=='#')
            tmp1*=-1;
    }
    answer+=tmp2;
    answer+=tmp1;
    return answer;
}
