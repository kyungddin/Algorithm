#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    const int row = board.size();
    const int col = board[0].size();
    
    vector<stack<int>> dollGame;
    dollGame.resize(row);
    
    // 1. 인형뽑기 구현
    for (int i = 0; i < col; i++)
    {
        for (int j = row - 1; j >=0; j--)
        {
            if(board[j][i]!= 0)
                dollGame[i].push(board[j][i]);
        }
    }
    
    // 2. moves대로 집어넣기
    stack<int> basket;
    int doll = 0;
    
    for (auto action : moves)
    {
        if (dollGame[action-1].size() != 0)
        {
            doll = dollGame[action-1].top();
            dollGame[action-1].pop();
            
            if (basket.size() == 0) 
                basket.push(doll);
            else if (doll != basket.top()) 
                basket.push(doll);
            else
            {
                answer += 2;
                basket.pop();
            }
        }
        else continue;
    }

    return answer;
}

/*
0 0 0 0 0
0 0 0 0 0
0 0 5 0 0
0 2 4 0 2
0 5 1 3 1

4
2
4
*/