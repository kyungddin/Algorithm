#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> stackIdx;
    
    const int size = prices.size();
    answer.resize(size);
    
    for (int idx = 0; idx < size; idx++)
    {
        while (!stackIdx.empty() && (prices[stackIdx.top()] > prices[idx]))
        {
           int topIdx = stackIdx.top();
           stackIdx.pop();
           answer[topIdx] = idx - topIdx;
        }
        stackIdx.push(idx);
    }
    
    int num = size - 1;
    
    while (stackIdx.size())
    {
        answer[stackIdx.top()] = num - stackIdx.top();
        stackIdx.pop();
    }
    
    /*
    for price in prices:
            if (stack != stack.empty and prices[stack.top] > price):
                while (! (stack.top > price)):
                    topIdx = stack.top
                    stack.pop
                    answer[topIdx] = topIdx - price.idx
            else:
                stack.push(price.idx)
    num = prices.size - 1
    for idx in stack:
        answer[idx] = num - idx
    */
    
    return answer;
}