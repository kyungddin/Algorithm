#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    answer -= lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (auto it = lost.begin(); it != lost.end(); )
    {
        auto a = find(reserve.begin(), reserve.end(), *it);
        
        if (a != reserve.end())
        {
            answer++;
            reserve.erase(a);
            it = lost.erase(it);
        }
        else
        {
            it++;
        }
    }
    
    for (auto l : lost)
    {
        auto a = find(reserve.begin(), reserve.end(), l-1);
        if (a != reserve.end())
        {
            answer++;
            reserve.erase(a);
        }
        else
        {
            auto b = find(reserve.begin(), reserve.end(), l+1);
            if (b != reserve.end())
            {
                answer++;
                reserve.erase(b);
            }
            else
            {
                continue;
            }
        }
    }
    
    return answer;
}