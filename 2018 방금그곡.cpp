//문자열을 받아서 두개의 시간을 2개의 함수를 이용해서 저장하고,
//문자열중에서 .를 찾아서 breakpoint vector에 저장한다.
//저장한 breakpoint를 이용해서 문자열에서 노래제목부분과, 음을 저장한다.
//문자열에서 #인 부분을 소문자로바꾸고 #을 제거한다.
//시간만큼 재생된 최종 문자열을 만든뒤에,
//해당되는 문자열이 존재한다면, 노래길이와 제목을 vector에 저장한다.
//반복문 돌려서 vector에서 max값을 갖는 원소를 출력한다 없으면 none을 출력한다.

#include <string>
#include <vector>

using namespace std;

int timetoint1(string time) {
    int Time;
    Time = (time[0] - 48) * 600 + (time[1] - 48) * 60 + (time[3] - 48) * 10 + (time[4] - 48);
    return Time;
}

int timetoint2(string time) {
    int Time;
    Time = (time[6] - 48) * 600 + (time[7] - 48) * 60 + (time[9] - 48) * 10 + (time[10] - 48);
    return Time;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int starttime, endtime;
    string subject, sound;
    string finalsong;
    vector<pair<string, int>> tmp;


    for (int i = 0;i < musicinfos.size();i++) {
        vector<int> breakpoint;

        for (int j = 0;j < musicinfos[i].size();j++)
        {
            if (musicinfos[i][j] == ',') 
                breakpoint.push_back(j);
            
        }

        finalsong = "";
        starttime = timetoint1(musicinfos[i]);
        endtime = timetoint2(musicinfos[i]);
        subject = musicinfos[i].substr(breakpoint[1] + 1, breakpoint[2] - breakpoint[1] - 1);
        sound = musicinfos[i].substr(breakpoint[2] + 1);

        
        for (int j = 0;j < sound.size();j++)
            if (sound[j] == '#')
                sound[j - 1] = sound[j - 1] + 'a' - 'A';


        for (int j = 0;j < m.size();j++)
            if (m[j] == '#')
                m[j - 1] = m[j - 1] + 'a' - 'A';

        while (sound.find("#") != -1) {
            sound.erase(sound.find("#"),1);
        }
        while (m.find("#") != -1) {
            m.erase(m.find("#"),1);
        }


        for (int j = 0;j < endtime - starttime;j++) {
            finalsong += sound[j % sound.size()];
        }

        int idx = finalsong.find(m, 0);

        if (idx != -1)
            tmp.push_back(make_pair(subject, endtime - starttime));
    }
    int max = 0;
    for (int i = 0;i < tmp.size();i++) {
        if (max < tmp[i].second)
            max = tmp[i].second;
    }

    for (int i = 0;i < tmp.size();i++)
        if (max == tmp[i].second) {
            answer = tmp[i].first;
            break;
        }

    if (answer == "")
        answer = "(None)";

    return answer;
}
