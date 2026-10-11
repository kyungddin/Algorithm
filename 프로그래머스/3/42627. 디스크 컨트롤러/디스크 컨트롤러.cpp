#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int push_time = 0;
    
    queue<pair<int, int>> process;
    queue<int> turnaroundTime;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    
    sort(jobs.begin(), jobs.end());
    
    while ( !jobs.empty() || !process.empty() || !heap.empty()) 
    {
        // jobs에 있는 적절한 job을 heap에 넣기
        while (!jobs.empty() && jobs.front()[0] <= time)
        {
            heap.push(make_pair(jobs.front()[1], jobs.front()[0]));
            jobs.erase(jobs.begin());
        }
        
        // 만약 process가 작업을 완료했다면 (turnaroundTime 업데이트 후 process 비우기)
        if ( !process.empty() && process.front().first == ( time - push_time) )
        {
            turnaroundTime.push(time - process.front().second);
            process.pop();
        }
        
        // process가 비워져있고.. heap에 작업이 있다면
        if (process.empty() && !heap.empty())
        {
            push_time = time;
            process.push(make_pair(heap.top().first, heap.top().second));
            heap.pop();
        }
        
        time++;
    }
    
    int sum = 0;
    int size = turnaroundTime.size();
    
    while (!turnaroundTime.empty())
    {
        sum += turnaroundTime.front();
        turnaroundTime.pop();
    }
        
        
    answer = sum / size;
    
    return answer;
}