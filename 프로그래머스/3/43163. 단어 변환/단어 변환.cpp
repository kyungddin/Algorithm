#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <climits>

using namespace std;

void DFS(string begin, string target, vector<string>& words, map<string, bool>& visited, int count, int& answer)
{
    // 1. 종료 조건 (최단 거리도 보장할 것)
    if (begin == target)
    { 
        answer = min(answer, count);
        return;
    }
    
    for (auto word : words)
    {
        int match_counter = 0;
        
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == begin[i]) match_counter++;
        }
        
        if (match_counter == word.size() - 1 && visited[word] == false)
        {
            visited[word] = true;
            DFS(word, target, words, visited, count+1, answer);
            
            // DFS에서는 현재 탐색 중인 경로 안에서만 같은 단어를 재방문 못하게 해야 함
            // 즉, DFS에서는 백트래킹이 필요하다. 그러나 BFS는 필요 X (방문 거리가 항상 최단거리)
            visited[word] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = INT_MAX;
    map<string, bool> visited;
    
    visited[begin] = true;
    
    DFS(begin, target, words, visited, 0, answer);
    
    if (answer == INT_MAX)
    {
        return 0;
    }
    
    return answer;
}