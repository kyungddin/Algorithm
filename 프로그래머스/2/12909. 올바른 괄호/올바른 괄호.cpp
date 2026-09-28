#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> parentStack;

    for (char ch : s)
    {
        if(ch == ')')
        {
            if(parentStack.size() == 0) return false;
            if(parentStack.top() == '(') parentStack.pop();
        }
        else
            parentStack.push(ch);
    }
    
    if (parentStack.size() != 0 ) return false;
    return true;
}