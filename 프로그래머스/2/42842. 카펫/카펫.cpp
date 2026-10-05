#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int max = brown + yellow;
    
    int row, col;
    int rowY, colY;
    
    for (int i = 1; i <= max; i++)
    {
        if (max % i == 0)
        {
            row = max / i;
            col = i;
        }
        
        rowY = row - 2;
        colY = col - 2;
        
        if (rowY <= 0 || colY <= 0) continue;
        
        if (rowY * colY == yellow)
        {
            answer.push_back(row);
            answer.push_back(col);
            
            return answer;
        }
    }
    
    //return answer;
}