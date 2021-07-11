//우선 dic에 A~Z까지 추가해준다.
//첫번째 반복문은 최종적으로 제거되고 남은 글자가 없어야하므로, msg가 ""이될때까지 반복한다. 
//첫번째 for문에서는 글자길이가 언제까지 가능한지 찾는다. i가 가능한 글자길이가 된다.
//만약에 특정 길이에서 가능하다면 flag가 true가 되고 불가능하다면 flag가 false가 되어 최종적으로 성공한 문자열이 tmp가 된다.
//우선 해당되는 인덱스를 출력한 뒤에, 최종적으로 성공한 문자열의 크기를 이용하여 msg의 w부분을 제거한뒤에 문자열+msg의 0번원소를 dic에 저장하는 것을 반복하다가,
//더이상 원소가 없을시에 종료한다.

#include <string>
#include <vector>


using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    string tmp = "";
    bool flag = false;
    int length = 0;
    int idx;

    vector<string> dic(26);
    for (int i = 0; i < 26; i++)
        dic[i] = i + 'A';



    while (msg.size() != 0) {
        for (int i = 0;i < msg.size();i++) {
            tmp = "";
            flag = false;
            for (int j = 0;j <= i;j++)
                tmp += msg[j]; 
            //i글자로 이루어진놈이 사전에 있냐?
            for (int j = 0;j < dic.size();j++)
                if (dic[j] == tmp) {
                    flag = true;
                    idx = j;
                }
            if (!flag) {
                length = i;
                tmp = tmp.substr(0,tmp.size()-1);
                break;
            }
        }
        answer.push_back(idx + 1);
        msg = msg.substr(tmp.size());
        dic.push_back(tmp + msg[0]);

    }
    return answer;
}
