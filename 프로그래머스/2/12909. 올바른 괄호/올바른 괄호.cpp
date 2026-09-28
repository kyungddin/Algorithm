#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<char> stackString;
    
    stackString.push(s[0]);
    
    for (int i = 1 ; i < s.size() ; i++)
    {
        if(!stackString.empty() && s[i] == ')' && stackString.top() == '(') stackString.pop();
        else stackString.push(s[i]);
    }
    
    if(stackString.empty()) answer = true;

    return answer;
}