#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> idxStack;
    int size = prices.size();
    int topIdx = 0;
    
    answer.resize(size);
    idxStack.push(0);
    
    for(int idx=1; idx < size; idx++)
    {
        while(!idxStack.empty() && (prices[idxStack.top()] > prices[idx]))
        {
            topIdx = idxStack.top();
            idxStack.pop();
            answer[topIdx] = idx - topIdx;
        }
        idxStack.push(idx);
    }
    
    const int MAX_VAL = size - 1;
    while (idxStack.size())
    {
        answer[idxStack.top()] = MAX_VAL - idxStack.top();
        idxStack.pop();
    }
    
    return answer;
}