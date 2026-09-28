#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> deqInteger(progresses.begin(), progresses.end());
    deque<int> deqSpeeds(speeds.begin(), speeds.end());
    
    int count = 0;
    
    while(!deqInteger.empty())
    {
        for(int i = 0 ; i < deqInteger.size() ; i++)
        {
            deqInteger[i] += deqSpeeds[i];
        }
        
        while(deqInteger.front() >= 100 && !deqInteger.empty())
        {
            deqInteger.pop_front();
            deqSpeeds.pop_front();
            count++;
        }
        
        if (count > 0) answer.push_back(count);
        count = 0;
    }
    
    return answer;
}