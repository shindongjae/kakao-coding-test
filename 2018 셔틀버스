//timetable을 Timetable에 int로 바꾼 값을 저장하여 마지막에 제일늦게 버스탄 사람시간을 저장하기 위해sort한다.
//그후 table배열에다가 Timetable이 작은 순서대로 버스에 탑승시킨다. i번째 원소가 i번째 버스이다.
//시간이 출발시간 전이면서 최대로 차지 않은 경우에 태우는 것을 반복한다.
//다 태운 후 만약에 마지막 버스에 최대로 정원이 차지 않았다면 마지막버스 출발시간에 타면 된다.
//만약에 마지막 버스에 정원이 다 찼다면, 가장 마지막으로 늦게탄 사람의 도착시간-1분에 도착하면 된다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    int table[11];

    
    vector<int> Timetable;
    int tmp;

    for (int i = 0;i < 10;i++)
        table[i] = 0;

    for (int i = 0;i < timetable.size();i++)
        Timetable.push_back(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2)));

    sort(Timetable.begin(), Timetable.end());

    int last;

    for (int i = 0;i < Timetable.size();i++) {
        for (int j = 9 * 60;j < 9 * 60 + n * t;j += t) {
            if (Timetable[i] <= j && table[(j - 9 * 60) / t] < m) {
                table[(j - 9 * 60) / t]++;
                last = Timetable[i];
                break;
            }
        }
    }


    if (table[n-1] < m)//제일 뒤에꺼가 안찬경우
    {
        string answer = "";
        tmp = 9 * 60 + (n - 1) * t;
        char a = tmp / 600 + 48;
        char b = tmp / 60 - (tmp / 600) * 10 + 48;
        char c = (tmp - (tmp / 60) * 60) / 10 + 48;
        char d = tmp % 10 + 48;

        answer += a;
        answer += b;
        answer += ":";
        answer += c;
        answer += d;
        return answer;
    }

    //제일뒤에꺼가 찬경우, 가장 마지막으로 타는데 성공한 사람시간 -1분에 와야한다.
    string answer = "";
    tmp = last - 1;
    char a = tmp / 600 + 48;
    char b = tmp / 60 - tmp / 600 * 10 + 48;
    char c = (tmp - (tmp / 60) * 60) / 10 + 48;
    char d = tmp % 10 + 48;

    answer += a;
    answer += b;
    answer += ":";
    answer += c;
    answer += d;
    return answer;
}
