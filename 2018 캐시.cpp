//캐시 내용을 <key, value>형태로 저장
//key는 사용된 시간을 저장하여 가장 작은 숫자를 지우고 붙여넣기함
//처음에 캐시 안에 해당 데이터가 존재하는지 찾는다.
//그후 존재하지 않는다면, 만약에 캐시 크기보다 적게찼다면 캐시안에 넣어주고,
//캐시가 다 찼다면 캐시 크기가 0이라면 그냥 answer+=5를 해주고, 캐시크기가 0이 아니라면
//LRU에 해당하는 원소를 찾아 지워주고 새로운 값을 넣어준다.

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map< int, string> cache;//key, value
    map< int, string>::iterator it;
    bool check = false;

    for (int i = 0;i < cities.size();i++) {
        for (int j = 0;j < cities[i].size();j++) {
            if (cities[i][j] >= 'A' && cities[i][j] <= 'Z')
                cities[i][j] = cities[i][j] + 'a' - 'A';
        }
    }

    for (int i = 0;i < cities.size();i++) {
        check = false;
        for (it = cache.begin();it != cache.end();it++) {
            if (it->second == cities[i]) //캐시안에 존재
            {
                check = true;
                cache.insert(make_pair(i, cities[i]));
                cache.erase(it->first);
                answer += 1;
                break;
            }
        }
        if (!check) {//캐시안에 존재하지 않음.
            if(cache.size()<cacheSize){
                 cache.insert(make_pair(i, cities[i]));
                 answer += 5;
            }
            else{
                int LRU = 999999999;
                if(cacheSize!=0){
                    for (it = cache.begin();it != cache.end();it++) {
                       if (it->first < LRU)
                          LRU = it->first;
                    }
                    cache.insert(make_pair(i, cities[i]));
                    cache.erase(LRU);
                }
                answer += 5;
            }
        }
    }
    return answer;
}
