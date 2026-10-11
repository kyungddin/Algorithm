#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for (auto score : scoville)
    {
        heap.push(score);
    }
    
    while (heap.top() < K)
    {
        if (heap.size() == 1) return -1;
        else
        {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();

            heap.push(a + b*2);

            answer++;
        }
    }
    
    return answer;
}