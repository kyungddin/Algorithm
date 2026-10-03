#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<vector<int>> visited;

bool isValid(int row, int col, int row_max, int col_max)
{
    if (row < 0 || row >= row_max || col < 0 || col >= col_max) return false;
    else return true;
}

void BFS(vector<vector<int>>& maps)
{
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    
    q.push(make_pair(0,0));
    
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            if(isValid(current.first+dr[i], 
                       current.second+dc[i], 
                       maps.size(), 
                       maps[0].size()
                      ) && maps[current.first+dr[i]][current.second+dc[i]] == 1)
            {
                if(visited[current.first][current.second] + 1 < visited[current.first+dr[i]][current.second+dc[i]])
                {
                    visited[current.first+dr[i]][current.second+dc[i]] = visited[current.first][current.second] + 1;
                    q.push(make_pair(current.first+dr[i], current.second+dc[i]));
                }
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int row = maps.size();
    int col = maps[0].size();
    
    visited.resize(row, vector<int>(col, INT_MAX));
    
    BFS(maps);
    
    if (visited[row-1][col-1] == INT_MAX) answer = -1;
    else answer = visited[row-1][col-1];
    
    return answer;
}