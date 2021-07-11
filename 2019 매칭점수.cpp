#include <string>
#include <vector>
#include <iostream>

using namespace std;

void lower(string& str) {//대문자를 소문자로 바꿔주는 함수.
    for (int i = 0;i < str.size();i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
}

string geturl(string page) {//문자열에서 url을 추출하는 함수.
    string tmp = "<meta property=\"og:url\" content=\"https://";
    int start = page.find(tmp) + tmp.size();
    int end = (page.substr(start)).find("\"/>");

    return page.substr(start, end);
}

vector<string> Find(string page) {//외부링크의 string vector를 추출하는 함수.
    int count = 0;
    vector<string> link;
    string tmp = "<a href=\"https://";
    while (page.find(tmp) != string::npos) {
        count++;
        page = page.substr(page.find(tmp) + tmp.size());
        int end = page.find("\">");
        link.push_back(page.substr(0, end));
    }
    return link;
}

bool alpha(char c) {
    return 'a' <= c && 'z' >= c;
}


int solution(string word, vector<string> pages) {
    int answer = 0;
    vector<int> scores(pages.size());//page별 점수를 저장.
    vector<string> url(pages.size());
    vector<vector<string>> link(pages.size());

    for (int i = 0;i < url.size();i++)
        url[i]=geturl(pages[i]);//url 저장

    for (int i = 0;i < pages.size();i++)
        link[i] = Find(pages[i]);//해당 페이지의 외부링크 저장.

    lower(word);
    for (int i = 0;i < pages.size();i++) {
        lower(pages[i]);//찾기위해 word와 pages 소문자로

        int score = 0;
        bool flag1 = false, flag2 = false;
        int start = pages[i].find(word, 0);//찾은 단어의 위치 저장
        while (start != string::npos) {//못찾을때까지
            if (start == 0 || !alpha(pages[i][start - 1]))
                flag1 = true;
            if ((start + word.size() == pages[i].size()) || (!alpha(pages[i][start + word.size()])))
                flag2 = true;
            if (flag1 && flag2)//만약에 단어단위로 일치하면
                score++;
            start=pages[i].find(word,start+1);//다음 단어를 찾는다.
            flag1=false;flag2=false;
        }
        scores[i] = score;//기본점수
    }
    //scores[i]:i번째 기본점수, url[i]:i번째 링크, link[i]: i번째 링크들 집합
   
    double Score[100];//점수 배열.
    for (int i = 0;i < pages.size();i++){
        Score[i] = (double)scores[i];
    }
    
    for(int i=0;i<pages.size();i++)//i번째 페이지에
        for(int j=0;j<link[i].size();j++)//j번째 link의
            for(int k=0;k<pages.size();k++){//원래 url위치를 찾아서 해당 위치에 점수를 더해준다.
                if(link[i][j]==url[k])
                    Score[k]=Score[k]+(double)scores[i]/link[i].size();
            }

    
    double maxscore=0;
    for (int i = 0;i < pages.size();i++) {
        if (maxscore < Score[i]) {
            maxscore = Score[i];
            answer = i;
        }
    }

    return answer;
}
