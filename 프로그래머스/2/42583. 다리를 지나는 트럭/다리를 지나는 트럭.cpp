#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

void truck_func(
    int bridge_length,
    int weight,
    int size,
    int time,
    int total_weights,
    int& answer,
    deque<pair<int, int>> bridge,
    queue<int>& start_truck,
    queue<int>& end_truck
)
{
    if (end_truck.size() == size)
    {
        answer = time;
        return;
    }
    
    if (!bridge.empty() && bridge.front().second == bridge_length)
    {
        end_truck.push(bridge.front().first);
        total_weights -= bridge.front().first;
        bridge.pop_front();
    }
    
    if (!start_truck.empty() && start_truck.front() + total_weights <= weight)
    {
        bridge.push_back(make_pair(start_truck.front(), 0));
        total_weights += start_truck.front();
        start_truck.pop();
    }
    
    for (auto& truck : bridge)
    {
        truck.second++;
    }
    
    truck_func(bridge_length, weight, size, time+1, total_weights, answer, bridge, start_truck, end_truck);
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int size = truck_weights.size();
    
    deque<pair<int, int>> bridge;
    queue<int> start_truck;
    queue<int> end_truck;
    
    for (auto truck : truck_weights)
    {
        start_truck.push(truck);
    }
    
    truck_func(bridge_length, weight, size, 0, 0, answer, bridge, start_truck, end_truck);
    
    return answer;
}