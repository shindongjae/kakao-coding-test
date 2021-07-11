#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char lower(char a){
    if(a>='A'&&a<='Z')
        return a-'A'+'a';
    else
        return a;
}


bool compare1(string str1, string str2){
    string tmpstr1="",tmpstr2="";
    for(int i=0;i<str1.size();i++){
        if(str1[i]>='0'&&str1[i]<='9')
            break;
        tmpstr1+=lower(str1[i]);
    }
    for(int i=0;i<str2.size();i++){
        if(str2[i]>='0'&&str2[i]<='9')
            break;
        tmpstr2+=lower(str2[i]);
    }
    int size=tmpstr1.size()>tmpstr2.size()?tmpstr2.size():tmpstr1.size();
    for(int i=0;i<size;i++){
        if(tmpstr1[i]>tmpstr2[i])
            return true;
        if(tmpstr2[i]>tmpstr1[i])
            return false;
    }
    if(tmpstr1.size()>tmpstr2.size())
        return true;
    if(tmpstr1.size()<tmpstr2.size())
        return false; 
    
    return true;
}


bool compare2(string str1, string str2){
    string tmpstr1="",tmpstr2="";
    int count=0;
    for(int i=0;i<str1.size();i++){
        if(str1[i]>='0'&&str1[i]<='9')
            break;
        tmpstr1+=lower(str1[i]);
        count++;
    }
    for(int i=0;i<str2.size();i++){
        if(str2[i]>='0'&&str2[i]<='9')
            break;
        tmpstr2+=lower(str2[i]);
    }
    if(tmpstr1!=tmpstr2)
        return true;
    
    tmpstr1="";
    tmpstr2="";
    for(int i=count;i<str1.size();i++){
        if(!(str1[i]>='0'&&str1[i]<='9'))
            break;
        tmpstr1+=str1[i];
    }
    for(int i=count;i<str2.size();i++){
        if(!(str2[i]>='0'&&str2[i]<='9'))
            break;
        tmpstr2+=str2[i];
    }
    if(stoi(tmpstr1)>stoi(tmpstr2))
        return false;
    else
        return true;
}



vector<string> solution(vector<string> files) {
    vector<string> answer=files;
    
    sort(answer.begin(),answer.end(),compare1);
    sort(answer.begin(),answer.end(),compare2);
    
    return answer;
}
