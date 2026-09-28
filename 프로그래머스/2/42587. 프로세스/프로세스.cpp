#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int, vector<int>> pq(priorities.begin(), priorities.end());
    
    deque<pair<int, int>> roundQueue;
    
    for (int i = 0 ; i < priorities.size() ; i++)
    {
        roundQueue.push_back(make_pair(priorities[i], i));
    }

    while(!roundQueue.empty())
    {
        if(roundQueue.front().first >= pq.top())
        {
            answer++;
            if(roundQueue.front().second == location) return answer;
            else 
            {
                roundQueue.pop_front();
                pq.pop();
            }
        }
        else
        {
            roundQueue.push_back(roundQueue.front());
            roundQueue.pop_front();
        }
    }
    
    return answer;
}