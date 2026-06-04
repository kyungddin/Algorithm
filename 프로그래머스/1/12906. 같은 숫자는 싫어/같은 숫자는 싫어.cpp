#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> uniqueStack;
    
    for (auto num : arr)
    {
        if(uniqueStack.size() == 0) uniqueStack.push(num);
        if(uniqueStack.top() != num) uniqueStack.push(num);
    }
    
    int size = uniqueStack.size();
    for (int i = 0; i < size; i++)
    {
        answer.push_back(uniqueStack.top());
        uniqueStack.pop();
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}