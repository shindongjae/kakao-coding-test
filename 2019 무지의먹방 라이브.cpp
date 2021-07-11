#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { return a.second < b.second;}
bool compare2(pair<int, int> a, pair<int, int> b) {  return a.first < b.first; }
int nextidx(int idx, int size) {  return (idx + 1) % size;}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int, int>> food;//몇번째, 남은양.

    long long sum = 0;
    for (int i = 0;i < food_times.size();i++)
        sum += (long long)food_times[i];
    if (sum <= k)
        return -1;  //만약에 음식개수보다 k가 크면 -1

    for (int i = 0;i < food_times.size();i++)
        food.push_back(make_pair(i + 1, food_times[i]));//인덱스,음식수 벡터 저장.


    sort(food.begin(), food.end(), compare);//음식수 적은거부터 저장.
    long long time = 0;
    int t = 0; //t는 x좌표
    int tmp = 0;

    if (food.size() == 1)//음식수가 1개면 1이 답이다.
        return 1;

    while (1) {//음식양이 바뀌는 지점을 찾아 바뀌는 지점 직전의 음식양*음식수를 time에 더해준다.
        //만약에 time보다 해당값이 크다면 다시 되돌려준다.
        if (t == 0) {
            time += food.size() * food[0].second;
            if (time > k) {
                time = 0;
                break;
            }
            for (int i = t;i < food.size() - 1;i++)
                if (food[i].second != food[i + 1].second) {
                    t = i + 1;
                    break;
                }
        }
        else {
            if (time + (food.size() - t) * (food[t].second - food[t - 1].second) <= k)
                time += (food.size() - t) * (food[t].second - food[t - 1].second);
            else
                break;
            for (int i = t;i < food.size() - 1;i++)
                if (food[i].second != food[i + 1].second) {
                    t = i + 1;
                    break;
                }
        }
    }

    vector<pair<int, int>> food2;
    //남아있는 음식만 추가해준다.
    //가장적은 음식양*음식수가 추가로 더 먹어야할 음식보다 무조건 적으므로
    //더 먹어야할 음식수를 food2의 사이즈로 나눠주면 먹어야할 차례의 음식이 나온다.
    if (t == 0) {
        for (int i = 0;i < food.size();i++)
            food2.push_back(make_pair(food[i].first, food[i].second));
    }
    else {
        for (int i = 0;i < food.size();i++)
            if (food[i].second - food[t - 1].second > 0)
                food2.push_back(make_pair(food[i].first, food[i].second - food[t - 1].second));
    }

    sort(food2.begin(), food2.end(), compare2);
    return food2[(k - time)%food2.size()].first;
}
