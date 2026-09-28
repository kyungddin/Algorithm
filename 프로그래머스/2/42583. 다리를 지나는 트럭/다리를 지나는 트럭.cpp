#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int size = truck_weights.size();
    int count = 0;
    int total_weight = 0;
    
    deque<int> truck_waits;
    
    for(auto truck : truck_weights)
    {
        truck_waits.push_back(truck);
    }
    
    deque<pair<int, int>> bridge;
    
    while(count != size)
    {
        // 1. 시간올리기
        answer++;
        for (int i = 0 ; i < bridge.size(); i++)
        {
            bridge[i].second++;
        }
        
        // 2. 건넜는지 체크하기
        if (!bridge.empty() && bridge.front().second >= bridge_length)
        {
            total_weight -= bridge.front().first;
            bridge.pop_front();
            count++;
        }
        
        // 3. 새 트럭 올리기
        if (!truck_waits.empty() && total_weight + truck_waits.front() <= weight)
        {
            bridge.push_back(make_pair(truck_waits.front(), 0));
            total_weight += truck_waits.front();
            truck_waits.pop_front();
        }
    }
    
    return answer;
}