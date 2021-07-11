//list는 지워야할 좌표를 저장하는 int,int벡터
//만약에 list.empty()가 참이라면 더이상 바꿀 벡터가 없는 경우니 종료한다.
//list배열을 초기화하고, for문을 돌려 check함수를 통하여 2*2블록을 제거해야할지 결정한다.
//check함수는 2*2배열이 모두 같으면서 공백이 아닌지 확인한다. check함수가 참이면 해당 좌표를 list에 추가한다.
//list값에 저장된 값을 이용하여 del함수로 제거한다. 정해진 좌표를 빈칸으로 채운다.
//마지막 arrangement함수로 빈 부분을 땡겨줘야 하는데, 해당 위치가 빈칸이고 그 위칸이 빈칸이 아니라면
//해당위치를 위칸의 원소로 채우고 그 위칸이 빈칸이 되도록한다.
//다음을 한줄마다 m번씩 반복하게 하여 모든 경우에도 제대로 땡겨질수 있도록 반복하였다.
//list.empty()가 참이될때까지 해당 내용을 반복한 뒤에, 빈칸의 개수를 새서 answer를 리턴한다.
#include <string>
#include <vector>


using namespace std;

bool check(int m, int n, vector<string> board) {
    if (board[m][n] == board[m + 1][n] && board[m + 1][n] == board[m][n + 1]
        && board[m + 1][n] == board[m + 1][n + 1] && board[m][n] != ' ')
        return true;
    else
        return false;
}

vector<string> del(int m, int n, vector<string> board) {
    vector<string> Board = board;
    Board[m][n] = ' ';
    Board[m][n + 1] = ' ';
    Board[m + 1][n] = ' ';
    Board[m + 1][n + 1] = ' ';

    return Board;
}

vector<string> arrangement(int m, int n, vector<string> board) {
    vector<string> Board = board;
    for (int i = 0;i < n;i++) {
        for (int k = 0;k < m;k++) {
            for (int j = m - 1;j > 0;j--)
                if (Board[j][i] == ' ' && Board[j-1][i] != ' ') {
                    Board[j][i] = Board[j-1][i];
                    Board[j-1][i] = ' ';
                }
        }
    }
    return Board;
}


int solution(int m, int n, vector<string> board) {
    vector<string> Board = board;
    int answer = 0;
    vector<pair<int, int>> list;
    vector<pair<int, int>> empty;

    do {
        list = empty;
        for (int i = 0;i < m - 1;i++)
            for (int j = 0;j < n - 1;j++) {
                if (check(i, j, Board))//없어져야 하는 부분 list로 저장
                    list.push_back(make_pair(i, j));
            }

        for (int i = 0;i < list.size();i++)
            Board = del(list[i].first, list[i].second, Board);
        Board = arrangement(m, n, Board);
    } while (!list.empty());

    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            if (Board[i][j] == ' ')
                answer++;
    return answer;
}
