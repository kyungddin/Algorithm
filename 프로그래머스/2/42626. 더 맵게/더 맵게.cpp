#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> scoHeap;
    
    for (auto num : scoville)
    {
        scoHeap.push(num);
    }
    
    while(scoHeap.top() < K)
    {
        if(scoHeap.size() < 2) return -1; 
        int first, second, mixed;
        first = scoHeap.top();
        scoHeap.pop();
        second = scoHeap.top();
        scoHeap.pop();
        
        mixed = first + (second * 2);
        scoHeap.push(mixed);
        
        answer++;
    }
    
    return answer;
}