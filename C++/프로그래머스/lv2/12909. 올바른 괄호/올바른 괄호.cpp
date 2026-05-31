#include<string>
#include <iostream>
#include <queue>

using namespace std;

deque<char> q;

bool solution(string s)
{
    bool answer = false;
    
    for(int i=0; i<s.size(); i++){
        q.push_back(s[i]);
        if(q.size()==1) continue;
        
        int k = q.size()-1;
        
        if(q[k] == ')' && q[k-1] == '(') {
            q.pop_back();
            q.pop_back();
        }
    }
    
    if(q.empty()) answer = true;

    return answer;
}