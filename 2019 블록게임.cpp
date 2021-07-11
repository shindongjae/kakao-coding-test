#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int answer=0;

void eraseA(vector<vector<int>> &board, int i, int j){
    if(j+2>=board.size()||i+1>=board.size())
        return;
    vector<int> tmp;
    for(int a=i;a<i+2;a++)
        for(int b=j;b<j+3;b++){
            tmp.push_back(board[a][b]);
        }
    
    sort(tmp.begin(),tmp.end(),greater<int>());
    
    if((tmp[5]==-1)&&(tmp[4]==-1)&&(tmp[0]==tmp[1])&&(tmp[1]==tmp[2])&&(tmp[2]==tmp[3])&&tmp[0]!=0&&tmp[0]!=-1)
    {
        answer++;
        board[i][j]=0;
        board[i][j+1]=0;
        board[i][j+2]=0;
        board[i+1][j]=0;
        board[i+1][j+1]=0;
        board[i+1][j+2]=0;
    }
}

void eraseB(vector<vector<int>> &board, int i, int j){
    if(i+2>=board.size()||j+1>=board.size())
        return;
    vector<int> tmp;
    for(int a=i;a<i+3;a++)
        for(int b=j;b<j+2;b++){
            tmp.push_back(board[a][b]);
        }
    
    sort(tmp.begin(),tmp.end(),greater<int>());

    if((tmp[5]==-1)&&(tmp[4]==-1)&&(tmp[0]==tmp[1])&&(tmp[1]==tmp[2])&&(tmp[2]==tmp[3])&&tmp[0]!=0&&tmp[0]!=-1)
    {
        answer++;
        board[i][j]=0;
        board[i][j+1]=0;
        board[i+1][j]=0;
        board[i+1][j+1]=0;
        board[i+2][j]=0;
        board[i+2][j+1]=0;
    }
}


int solution(vector<vector<int>> board) {
    //->방향이 i
    //a[j][i]꼴.
    
    for(int t=0;t<200;t++){//같은 내용을 200번 반복한다.
    
    for(int i=0;i<board.size();i++)//제일위에 2개씩 검은블록을 쌓는다.
        if(board[0][i]==0)
            for(int j=1;j<board.size();j++){
                if(board[j-1][i]==0&&board[j][i]!=0){
                    board[j-1][i]=-1;
                    if(j-2>=0)
                        board[j-2][i]=-1;
                    break;
                }
                if(j==board.size()-1){
                    board[board.size()-1][i]=-1;
                    board[board.size()-2][i]=-1;
                }
            }
    
   
    
     for(int i=0;i<board.size();i++)//2*3안에 한가지숫자로 이루어진 블록 4개+검정블록 2개로 이루어져잇다면 지운다.
        for(int j=0;j<board.size();j++)
        {
            eraseA(board,i,j);
            eraseB(board,i,j);
        }
    
    
     for(int i=0;i<board.size();i++)//검정블록을 다시 0으로 바꾼다.
        for(int j=0;j<board.size();j++)
            if(board[i][j]==-1)
                board[i][j]=0;


    }
    
    return answer;
}
