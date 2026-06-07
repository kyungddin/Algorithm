#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    // 1. Init
    deque<pair<int, int>> pDeque;
    
    for (int idx = 0; idx < priorities.size(); idx++)
    {
        pDeque.push_back(make_pair(priorities[idx], idx));
    }
    
    bool flag = false;
    while(pDeque.size())
    {
        pair<int, int> priority = pDeque.front();
        pDeque.pop_front();
        for(int idx = 0; idx < pDeque.size(); idx++)
        {
            if(priority.first < pDeque[idx].first)
            {
                pDeque.push_back(priority);
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            answer++;
            if(priority.second == location) return answer;
        }
        flag = false;
    }
}