#include <string>
#include <stack>

using namespace std;

bool solution(string sentence)
{
    bool answer = true;
    stack<char> cStack;
    
    for (auto word : sentence)
    {
        if (cStack.empty()) cStack.push(word);
        else if (word == '(') cStack.push(word);
        else if (word == ')')
        {
            if (cStack.top() == '(') cStack.pop();
            else if (cStack.top() == ')') cStack.push(word);
        }
    }
    
    if (!cStack.empty()) answer = false;

    return answer;
}