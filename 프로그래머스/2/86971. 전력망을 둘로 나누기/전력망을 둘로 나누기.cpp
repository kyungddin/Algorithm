#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(
    int vertex,
    vector<vector<int>>& graph,
    vector<bool>& visited,
    int& count
)
{
    queue<int> q;
    visited[vertex] = true;
    q.push(vertex);
    count++;
    
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for (auto next : graph[current])
        {
            if(visited[next] == false)
            {
                q.push(next);
                visited[next] = true;
                count++;
            }
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    
    // Variable Setting
    int answer = INT_MAX;
    int network = 0;
    int count = 0;
    
    vector<int> vecCount;
    
    // Graph Setting
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);
    
    // Fill the graph (Brute Force)
    int size = wires.size();
    for (int i = 0; i < size; i++)
    {
        graph.clear();
        visited.clear();
        graph.resize(n+1);
        visited.resize(n+1, false);
        
        for (int j = 0; j < size; j++)
        {
            if (i == j) continue;
            
            int nodeA = wires[j][0];
            int nodeB = wires[j][1];
            
            graph[nodeA].push_back(nodeB);
            graph[nodeB].push_back(nodeA);
        }
        
        // BFS 수행 (1~9 노드에 대해)
        for (int k = 1; k <= n; k++)
        {
            if (visited[k] == true) continue;
            else
            {
                BFS(k, graph, visited, count);
                network++;
                vecCount.push_back(count);
                count = 0;
            }
        }
        
        // Network 2인지 체크
        if (network == 2)
        {
            sort(vecCount.begin(), vecCount.end(), greater<int>());
            int result = vecCount[0] - vecCount[1];
            answer = min(answer, result);
        }
        
        // 변수 초기화
        network = 0;
        count = 0;
        vecCount.clear();
    }
    
    return answer;
}