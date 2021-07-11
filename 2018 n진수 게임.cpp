#include <string>
#include <vector>
#include <stack>

using namespace std;


string solution(int n, int t, int m, int p) {//n진법, 숫자갯수t, 참가인원m명 튜브의순서 p번째
    string answer = "";
    vector<int> lis;
    stack<int> num;
    
    for(int i=0;i<t*m;i++){
        int k=i;
        do{
            num.push(k%n);
            k/=n;
        }while(k!=0);
        while(!num.empty()){
            lis.push_back(num.top());
            num.pop();
        }                    
    }
    int count=0;
    for(int i=0;i<lis.size();i++)
    {
        if(i%m==p-1){
            count++;
            if(lis[i]>=0&&lis[i]<=9)
                answer+=(lis[i]+48);
            else
                answer+=lis[i]+'A'-10;
        }
        if(count==t)
            break;
    }
    
    return answer;
}
