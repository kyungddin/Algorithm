#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void BFS(int vertex)
{
    queue<int> q;
    
    visited[vertex] = true;
    q.push(vertex);
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (visited[next] == false)
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int N = computers.size();
    
    // graph 및 visited 자료구조 resize
    graph.resize(N);
    visited.resize(N, false);
    
    // graph 정보 초기화하기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < computers[i].size(); j++)\
        {
            if (i == j) continue;
            
            if (computers[i][j] == 1) graph[i].push_back(j);
        }
    } 
    
    for(int i = 0; i < N; i++)
    {
        if (visited[i] == false)
        {
            BFS(i);
            answer++;
        }
        else
        {
            continue;
        }
    }
    
    return answer;
}