//문자열에서 시,분,초를 가져와서 밀리초단위로 변환
//마지막 T부분은 문자열의 길이를 이용해서 저장.
//endtime을 먼저 구하고 T를 이용하여 starttime을 구한뒤에,
//최대인 지점은 시작과 끝 전후1초사이인 경우만 확인하면 된다.
//기준 시간을 기준으로 비교하는 시간의 끝부분이나 첫부분이 그 안에 들어오는 경우,
//시작이 기준시간의 첫부분보다 길면서 끝이 기준시간의 끝부분보다 긴 경우 1초 처리량에 포함된다.
//모든 시간을 기준으로 반복문을 돌려서 같은내용을 반복하여 최댓값을 구한다.
//전후시작끝 4가지 모든경우 계산을 해야한다고 생각했지만, 실제로는 기준시간의 시작 전 1초부분만 계산하면 되는데 그 이유는 잘 모르겠다.


#include <string>
#include <vector>

using namespace std;

int Time(string time) {
    int tmp;
    tmp = ((time[11] - 48) * 10 + (time[12] - 48)) * 3600;//시간 초로
    tmp += ((time[14] - 48) * 10 + (time[15] - 48)) * 60;//분 초로
    tmp += (time[17] - 48) * 10 + time[18] - 48;//초까지 더함
    tmp *= 1000;
    tmp += (time[20] - 48) * 100 + (time[21] - 48) * 10 + time[22] - 48;

    return tmp;
}

int StartTime(string time, int endtime) {
    int tmp;
    //2s -길이 26
    //2.0s 길이 28
    //2.90s 길이 29
    //2.000s 길이 30

    tmp = (time[24] - 48) * 1000;
    if (time.size() >= 28)
        tmp += (time[26] - 48) * 100;
    if (time.size() >= 29)
        tmp += (time[27] - 48) * 10;
    if (time.size() >= 30)
        tmp += time[28] - 48;

    return endtime - tmp + 1;
}

int solution(vector<string> lines) {
    int endtime, starttime;
    int max = 0;
    int count = 0;
    vector<pair<int, int>> times;//시작시간 끝시간

    for (int i = 0;i < lines.size();i++) {
        endtime = Time(lines[i]);//시간을 밀리초로 변환.
        starttime = StartTime(lines[i], endtime);
        times.push_back(make_pair(starttime, endtime));
    }

    for (int i = 0;i < times.size();i++) {
        for (int j = 0;j < times.size();j++)
            if (((times[i].first>= times[j].second) && ((times[i].first - 999) <= (times[j].second))) ||
                ((times[i].first>= times[j].first) && ((times[i].first - 999) <= (times[j].first)))   ||
                ((times[j].second >= times[i].first) && (times[j].first <= (times[i].first - 999)))) 
                count++;    
        if (count > max)
            max = count;
        count = 0;
        

    }
    return max;
}
