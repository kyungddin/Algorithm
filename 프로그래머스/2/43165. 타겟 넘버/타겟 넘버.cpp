#include <string>
#include <vector>

using namespace std;

vector<int> graph;
int result = 0;

void DFS(int sum, int index, int goal)
{
    if (index == graph.size())
    {
        if (sum == goal) 
        {
           result++;
        }
        
        return;
    }
    
    DFS(sum + graph[index], index + 1, goal);
    DFS(sum - graph[index], index + 1, goal);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int N = numbers.size();
    
    for (auto n : numbers) graph.push_back(n);
        
    DFS(0, 0, target);
    answer = result;
    
    return answer;
}