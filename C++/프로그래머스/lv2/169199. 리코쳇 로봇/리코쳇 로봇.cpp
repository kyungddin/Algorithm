#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

// Global Variable
int answer = INT_MAX;
int row, col;
vector<int> dy = {1, -1, 0, 0};
vector<int> dx = {0, 0, 1, -1};
int ry, rx;
vector<vector<int>> visit;

void BFS(vector<string>& board){
    queue<vector<int>> q;
    q.push({ry, rx, 0});
    visit[ry][rx] = 1;
    
    while(!q.empty()){
        vector<int> tmp = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int ny = tmp[0];
            int nx = tmp[1];
            int c = tmp[2];
    
            while(1){
                int ty = ny + dy[i];
                int tx = nx + dx[i];
                
                if(ty<0 || ty>=row || tx<0 || tx >= col) break;
                if(board[ty][tx] == 'D') break;
                
                ny = ty;
                nx = tx;
            }
            
            if(visit[ny][nx] == 1) continue;
            
            else{
                if(board[ny][nx]== 'G'){
                    answer = c+1;
                    return;
                }
                
                visit[ny][nx] = 1;
                q.push({ny, nx, c+1});
            }
            
        }   
    }
    
    if(answer == INT_MAX) answer = -1;
}

int solution(vector<string> board) {
    
    // Variable Setting
    row = board.size();
    col = board[0].size();
    
    visit.resize(row, vector<int>(col, 0));
    
    // Main Logic
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(board[i][j] == 'R'){
                ry = i;
                rx = j;
            }
        }
    }
    
    BFS(board);
    
    return answer;
}