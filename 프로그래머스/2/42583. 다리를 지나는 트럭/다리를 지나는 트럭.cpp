#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> queueTruck;
    deque<pair<int, int>> bridge;
    queue<int> resultTruck;
    
    int size = truck_weights.size();
    
    for(int i = 0; i <size; i++)
    {
        queueTruck.push(truck_weights[i]);
    }
    
    int weightSum = 0;
    while(resultTruck.size() != size)
    {
        answer++;
        for(int i=0 ; i < bridge.size(); i++) // 초 추가하기
        {
            bridge[i].second++;
        }
        
        if(!bridge.empty() && bridge.front().second > bridge_length) // 다리에서 빼내는 로직
        {
            resultTruck.push(bridge.front().first);
            weightSum -= bridge.front().first;
            bridge.pop_front();
        }
        
        if(!queueTruck.empty() && weightSum + queueTruck.front() <= weight &&  bridge.size() <= bridge_length) // 다리에 넣는 로직
        {
            bridge.push_back(make_pair(queueTruck.front(), 1));
            weightSum += queueTruck.front();
            queueTruck.pop();   
        }
    }
    
    return answer;
}