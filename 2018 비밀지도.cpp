//vector<string>을 길이가 n인 빈칸으로채워진 n개의 string으로 만들어준 뒤에
//arr에서 받은 값을 2로 나눠가면서 2진수 값을 구해서 제일 오른쪽부터 1인경우 채워준다.

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;


    for (int i = 0;i < n;i++) {
        answer.push_back("");
        for (int j = 0;j < n;j++) {
            answer[i] += ' ';
        }
    }

    for (int i = 0;i < arr1.size();i++)
    {
        int t = arr1[i];
        for (int j = 0;j < n;j++) {
            if (t % 2 == 1)
                answer[i][n - j - 1] = '#';
            t = t / 2;
        }
    }

    for (int i = 0;i < arr2.size();i++)
    {
        int t = arr2[i];
        for (int j = 0;j < n;j++) {
            if (t % 2 == 1)
                answer[i][n - j - 1] = '#';
            t = t / 2;
        }
    }

    return answer;
}
