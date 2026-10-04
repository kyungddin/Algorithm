#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

void BFS(
    const string& begin, 
    const string& target,
    vector<string>& words,
    map<string, bool>& visited,
    int& answer
)
{
    queue<pair<string, int>> q;
    
    visited[begin] = true;
    q.push(make_pair(begin, 0));
    
    int size = words[0].size();
    
    while (!q.empty())
    {
        pair<string, int> current = q.front();
        q.pop();
        
        if (current.first == target)
        {
            answer = current.second;
            return;
        }
        
        for (auto word : words)
        {
            int different_count = 0;
            
            for (int i = 0; i < size; i++)
            {
                if (current.first[i] != word[i]) different_count++;
            }
            
            if (different_count == 1 && visited[word] == false)
            {
                visited[word] = true;
                q.push(make_pair(word, current.second+1));
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string, bool> visited;
    
    BFS(begin, target, words, visited, answer);
    
    return answer;
}