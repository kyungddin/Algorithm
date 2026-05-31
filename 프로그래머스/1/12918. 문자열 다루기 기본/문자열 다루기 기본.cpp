#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if (s.size() !=4 && s.size() != 6)
    {
        answer = false;
        return answer;
    }
    
    else
    {
        for (auto c : s)
        {
            if (c >= 'A' && c <= 'z')
            {
                answer = false;
                return answer;
            }
            else continue;
        }
    }
    
    return answer;
}