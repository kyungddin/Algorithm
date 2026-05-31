#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    
    // Variable Setting
    int answer = 0;
    string tmp;
    int n = board.size();
    
    // Main Logic
    tmp = board[h][w];
    
    if((h-1) >= 0){
        if(board[h-1][w] == tmp) answer++;
    }
    
    if((w-1) >= 0){
        if(board[h][w-1] == tmp) answer++;
    }
    
    if((h+1)<n){
        if(board[h+1][w] == tmp) answer++;
    }
    
    if((w+1)<n){
        if(board[h][w+1] == tmp) answer++;
    }
    
    return answer;
}