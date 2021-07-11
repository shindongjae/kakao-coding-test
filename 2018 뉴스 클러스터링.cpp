//대소문자 구분않기 위해서 대문자를 전부 소문자로 바꿔준다.
//lis1, lis2에 각각 2개씩 묶은 특수문자없이 대소문자로 이루어진 가능한 소문자를 넣어준다
//모든 lis1의 원소에 대해 lis2의 원소가 존재하는지 확인한다.
//check2배열을 이용하여 한번 이용된 lis2의 원소가 중복이용되지 않도록 한다.
//lis1중에서 일치하는 개수가 count가 되도록 한다.
//일치하는 개수를 구해서 count/lis1.size+lis2.size-count가 교집합/합집합개수가 될테니
//그값에 65536을 곱하면 답이된다.


#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> lis1, lis2;
    vector<bool> check2;
    int count=0;
    
    for(int i=0;i<str1.size();i++)
        if(str1[i]>='A'&&str1[i]<='Z')
            str1[i]=str1[i]+'a'-'A';
    for(int i=0;i<str2.size();i++)
        if(str2[i]>='A'&&str2[i]<='Z')
            str2[i]=str2[i]+'a'-'A';
    
    for(int i=0;i<str1.size()-1;i++)
        if(str1[i]>='a'&&str1[i]<='z'&&str1[i+1]>='a'&&str1[i+1]<='z')
        {
            string tmp;
            tmp.push_back(str1[i]);
            tmp.push_back(str1[i+1]);
            lis1.push_back(tmp);
        }
    
    for(int i=0;i<str2.size();i++)
        if(str2[i]>='a'&&str2[i]<='z'&&str2[i+1]>='a'&&str2[i+1]<='z')
        {
            string tmp;
            tmp.push_back(str2[i]);
            tmp.push_back(str2[i+1]);
            lis2.push_back(tmp);
            check2.push_back(false);
        }
    
    
    
    for(int i=0;i<lis1.size();i++){
        for(int j=0;j<lis2.size();j++)
        {
            if(lis1[i]==lis2[j]&&check2[j]==false)
            {
                count++;
                check2[j]=true;
                break;
            }
        }
    }
    
    if(lis1.size()==0&&lis2.size()==0)
        answer=65536;
    else
        answer=(65536*count)/(lis1.size()+lis2.size()-count);
    
    return answer;
}
