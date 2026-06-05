#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    deque<int> progressDeque;
    deque<int> speedDeque;
    
    for (auto num : progresses)
        progressDeque.push_back(num);
    
    for (auto num : speeds)
        speedDeque.push_back(num);
    

    int count = 0;
    while(progressDeque.size() != 0)
    {
        for(int i=0; i < progressDeque.size(); i++)
        {
            progressDeque[i] += speedDeque[i];
        }
        
        while(progressDeque.front() >= 100)
        {
            if(progressDeque.size() == 0) break;
            progressDeque.pop_front();
            speedDeque.pop_front();
            count++;
        }
        
        if (count > 0)
            answer.push_back(count);
        
        count = 0;
    }

    
    return answer;
}