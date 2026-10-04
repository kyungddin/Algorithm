#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool DFS(
    vector<vector<string>>& tickets,
    vector<bool>& visited,
    vector<string>& answer,
    string current,
    int count
)
{
    // 1. 종료 조건 (count가.. ticket의 size 라면.. 종료해야 함)
    if (count == tickets.size())
    {
        return true;
    }
    
    // 2. 해야 하는 것 (tickets를 돌면서 visit이 안된 놈에 대해서 departure와 dest 추출)
    for (int i = 0; i < tickets.size(); i++)
    {
        if (visited[i] == true) continue;

        string departure = tickets[i][0];
        
        if (current != departure) continue;
        
        string destination = tickets[i][1];
        visited[i] = true;
        answer.push_back(destination);
        
        if (DFS(tickets, visited, answer, destination, count+1))
        {
            return true;
        }
        
        answer.pop_back();
        visited[i] = false;
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    vector<bool> visited(tickets.size());
    
    answer.push_back("ICN");
    DFS(tickets, visited, answer, "ICN", 0);
    
    return answer;
}